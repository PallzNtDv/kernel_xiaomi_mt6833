#ifndef _SUSFS_IDA_COMPAT_H
        #define _SUSFS_IDA_COMPAT_H
        #include <linux/version.h>
        #include <linux/idr.h>
        #include <linux/gfp.h>
        #if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
        #ifndef SUSFS_HAVE_IDA_ALLOC_MIN
        #define SUSFS_HAVE_IDA_ALLOC_MIN
        static inline int ida_alloc_min(struct ida *ida, unsigned int min, gfp_t gfp)
        {
        	return ida_simple_get(ida, min, 0, gfp);
        }
        static inline void ida_free(struct ida *ida, unsigned int id)
        {
        	ida_simple_remove(ida, id);
        }
        #endif
        #endif
        #endif /* _SUSFS_IDA_COMPAT_H */