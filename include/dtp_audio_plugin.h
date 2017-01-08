#ifndef DTP_AUDIO_PLUGIN_H
#define DTP_AUDIO_PLUGIN_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

#define AUDIO_EXTRADATA_SIZE 4096

enum {
    DTP_AO_CMD_GET_LATENCY = 0x0,
    DTP_AO_CMD_GET_LEVEL,
    DTP_AO_CMD_GET_VOLUME,
    DTP_AO_CMD_GET_MAX = 0x99,

    DTP_AO_CMD_SET_VOLUME = 0x100,
    DTP_AO_CMD_SET_MAX
};

typedef struct {
    int channels, dst_channels;
    int samplerate, dst_samplerate;
    int data_width;
    int bps;
    int num, den;
    int extradata_size;
    unsigned char extradata[AUDIO_EXTRADATA_SIZE];
    int afmt;
    int audio_filter;
    int audio_output;
    void *avctx_priv;           // point to avcodec_context
    void *service_mgt;          // service manager context
} dtaudio_para_t;

struct ao_wrapper;

typedef int (*ao_init)(struct ao_wrapper *ao, dtaudio_para_t *para);
typedef int (*ao_start)(struct ao_wrapper *ao);
typedef int (*ao_pause)(struct ao_wrapper *ao);
typedef int (*ao_resume)(struct ao_wrapper *ao);
typedef int (*ao_write)(struct ao_wrapper *ao, uint8_t * buf, int size);
typedef int (*ao_get_parameter)(struct ao_wrapper *ao, int cmd,
                                unsigned long arg);
typedef int (*ao_set_parameter)(struct ao_wrapper *ao, int cmd,
                                unsigned long arg);
typedef int (*ao_stop)(struct ao_wrapper *ao);

typedef struct ao_wrapper {
    int id;
    const char *name;
    dtaudio_para_t para;

    ao_init init;
    ao_start start;
    ao_pause pause;
    ao_resume resume;
    ao_write write;
    ao_get_parameter get_parameter;
    ao_set_parameter set_parameter;
    ao_stop stop;

    struct ao_wrapper *next;
    void *ao_priv;
} ao_wrapper_t;

#ifdef  __cplusplus
}
#endif

#endif
