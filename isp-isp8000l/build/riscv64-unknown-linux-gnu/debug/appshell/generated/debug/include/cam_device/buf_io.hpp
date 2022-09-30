/******************************************************************************\
|* Copyright (c) 2020 by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")       *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

#pragma once

#include "cam_common.hpp"
#include <mim_ctrl/mim_ctrl_api.h>
#include <mim_ctrl/mim_ctrl_common.h>

#include <ebase/trace.h>
#include <vector>
#include <list>
#include "cam_device_api.hpp"
#include <json/json.h>

namespace camdev {

struct Xim : ItfBufferCb, Ctrl {
  Xim();
  ~Xim();

  void bufferCb(MediaBuffer_t *) override {}

  static void cbCompletion(MimCtrlCmdId_t , int32_t, void *);
  RESULT ximUsrLoadBuffer(PicBufMetaData_t *pPicBuffer, void *pContext);

  RESULT start(void *) override;

  RESULT stop() override;

  MimCtrlContextHandle_t  hCtrl = NULL;
  uint32_t ximLoadBufferNumber = 0;
  uint32_t ximLoadBufferCnt = 0;

  PicBufMetaData_t bufferFormat;
  RESULT ximCheckBufferFormat(PicBufMetaData_t *pPicBuffer);
  RESULT ximSetParameters(uint32_t frame_cnt, PicBufMetaData_t *BufFormat);

};

struct Xom : ItfBufferCb, CamStatus{
  Xom(ISPCORE_BUFIO_ID idx, uint32_t eQlength, uint32_t bQlength);
  virtual ~Xom();
  void bufferCb(MediaBuffer_t *) override;

public:
  uint32_t                   FrameSkip_Max;       //!< Skip consecutive samples.
  uint32_t                   FrameIdx;            //!< Sample index.
  ISPCORE_BUFIO_ID             dma_idx;

  RESULT xomInit(uint8_t skip_interval);
  RESULT xomDeInit();
  RESULT xomStart();
  RESULT xomStop();
  RESULT xomWaitForBufferEvent(buffCtrlEvent_t * xomCtrlEvent, int timeout);
  RESULT xomDQBUF(MediaBuffer_t ** pBuf);
  RESULT xomQBUF(MediaBuffer_t * pBuf);

private:
  Xom();
  RESULT                     xomCtrlSendEvent(buffCtrlEvent_t *pEvent);
  RESULT                     xomStatsValidCheck();

  uint32_t                   MaxPendingEvents; //!< Number of commands that can be queued and thus be pending at a time.
  uint32_t                   MaxBuffers;
  osQueue                    CommandQueue;       //!< Command queue; holds elements of type @ref buffCtrlEvent_t.
  osQueue                    FullBufQueue;

};



/*Buffer related definitions*/
typedef uint64_t (*buffPoolTransfer)(uint64_t address, void * ctx);


    /*
     * ISP buffer pool cmds operatiuon guide:
     * init BufCtx from CtifApi.
     * setBuffParameters(physiacal_linear, or usr_ptr)
     * bufferPoolAddEntity()
     * bufferPoolKernelAddrMap()
     * setBufInfoToEngine()
     *
     * TBD for delete operations
     *
     */

class BuffPool:CamStatus{
public:
      BuffPool();
      ~BuffPool();

    struct BufCtx{
        BUFF_MODE buf_work_mode;
        std::list<BufIdentity *> buf_list;
        uint32_t frame_number = 0;
    };

    struct BufCtx buf_context;

    buffPoolTransfer funcUer2UserBuffTransfer;

    RESULT bufferPoolKernelAddrMap(uint32_t needRemap );
    RESULT buffPoolAddEntity(BufIdentity* buf);
    RESULT buffPoolClearBufList();

    RESULT setBuffParameters(BUFF_MODE buff_mode);
    BufCtx *getBuffPrameters();
    std::list<BufIdentity *> * getBuffPoolList();

};

class Bitf {
  struct BufIO_Ctrl:CamStatus{
    union{
      Xom * pXom;
      Xim * pXim;
    }io;
    BuffPool * pBufPool;
  };

  public:
    Bitf();
    ~Bitf();

  RESULT bitfSetOutputCtrl(ISPCORE_BUFIO_ID id, Xom * pXom);
  Xom* bitfGetOutputCtrl(ISPCORE_BUFIO_ID id);

  RESULT bitfSetInputCtrl(Xim * pXim);
  Xim* bitfGetInputCtrl();

  RESULT bitfSetBufferPoolCtrl(ISPCORE_BUFIO_ID id, BuffPool * pBufPool);
  BuffPool* bitfGetBufferPoolCtrl(ISPCORE_BUFIO_ID id);

  static RESULT bitfCheckBufSizeMax(uint32_t buf_size, ISPCORE_BUFIO_ID chain);
  static RESULT bitfCheckBufNumberMax(uint32_t buf_num, ISPCORE_BUFIO_ID chain);

  BUFF_MODE buf_work_mode;
  private:
  BufIO_Ctrl bufio_ctrl[ISPCORE_BUFIO_MAX];
};


}

