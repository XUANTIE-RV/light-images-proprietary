
#ifndef TUNING_COMMON_EXPORT_H
#define TUNING_COMMON_EXPORT_H

#ifdef TUNING_COMMON_STATIC_DEFINE
#  define TUNING_COMMON_EXPORT
#  define TUNING_COMMON_NO_EXPORT
#else
#  ifndef TUNING_COMMON_EXPORT
#    ifdef tuning_common_EXPORTS
        /* We are building this library */
#      define TUNING_COMMON_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define TUNING_COMMON_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef TUNING_COMMON_NO_EXPORT
#    define TUNING_COMMON_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef TUNING_COMMON_DEPRECATED
#  define TUNING_COMMON_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef TUNING_COMMON_DEPRECATED_EXPORT
#  define TUNING_COMMON_DEPRECATED_EXPORT TUNING_COMMON_EXPORT TUNING_COMMON_DEPRECATED
#endif

#ifndef TUNING_COMMON_DEPRECATED_NO_EXPORT
#  define TUNING_COMMON_DEPRECATED_NO_EXPORT TUNING_COMMON_NO_EXPORT TUNING_COMMON_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef TUNING_COMMON_NO_DEPRECATED
#    define TUNING_COMMON_NO_DEPRECATED
#  endif
#endif

#endif /* TUNING_COMMON_EXPORT_H */
