#ifdef __cplusplus
extern "C" {
#endif

#include <cam_calibdb/cam_calibdb_api.h>

void* create_CalibDb();
void destroy_CalibDb(void* thisC);
int32_t install_CalibDb(void* thisC, char* filename);
int32_t uninstall_CalibDb(void* thisC);
CamCalibDbHandle_t getCalibDbHandle(void* thisC);

#ifdef __cplusplus
}
#endif
