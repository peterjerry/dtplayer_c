#include "dt_setting.h"
#include "dt_ini.h"
#include "dt_log.h"

#include <stdlib.h>

dt_setting_t dtp_setting;

#define TAG "DTP-SETTING"

int dt_update_setting()
{
    char value[512];

    dtp_setting.log_level = 2;
    if(GetEnv("LOG","log.level",value) > 0)
        dtp_setting.log_level = atoi(value);
    // STREAM
    dtp_setting.stream_cache = 0;
    if(GetEnv("STREAM","stream.cache",value) > 0)
        dtp_setting.stream_cache = atoi(value);
    dtp_setting.stream_cache_size = 32*1024*1024; // remove later
    if(GetEnv("STREAM","stream.cachesize",value) > 0)
        dtp_setting.stream_cache_size = atoi(value);

    // DEMUXER
    dtp_setting.demuxer_probe = 0;
    if(GetEnv("DEMUXER","demuxer.probe",value) > 0)
        dtp_setting.demuxer_probe = atoi(value);
    dtp_setting.demuxer_probe_size = 1024*1024;
    if(GetEnv("DEMUXER","demuxer.probesize",value) > 0)
        dtp_setting.demuxer_probe_size = atoi(value);
    dtp_setting.demuxer_seek_keyframe = 1;
    if(GetEnv("DEMUXER","demuxer.seek.keyframe",value) > 0)
        dtp_setting.demuxer_seek_keyframe = atoi(value);

    // AUDIO
    dtp_setting.audio_downmix = 1;
    if(GetEnv("AUDIO","audio.downmix",value) > 0)
        dtp_setting.audio_downmix = atoi(value);

    // VIDEO
    dtp_setting.video_pts_mode = 0;
    if(GetEnv("VIDEO","video.pts_mode",value) > 0)
        dtp_setting.video_pts_mode = atoi(value);
    dtp_setting.video_out_type = 0;
    if(GetEnv("VIDEO","video.outtype",value) > 0)
        dtp_setting.video_out_type = atoi(value);

    // PLAYER
    dtp_setting.player_dump_mode = 0;
    if(GetEnv("PLAYER","player.dumpmode",value) > 0)
        dtp_setting.player_dump_mode = atoi(value);
    dtp_setting.player_noaudio = 0;
    if(GetEnv("PLAYER","player.noaudio",value) > 0)
        dtp_setting.player_noaudio = atoi(value);
    dtp_setting.player_novideo = 0;
    if(GetEnv("PLAYER","player.novideo",value) > 0)
        dtp_setting.player_novideo = atoi(value);
    dtp_setting.player_sync_enable = 1;
    if(GetEnv("PLAYER","player.sync.enable",value) > 0)
        dtp_setting.player_sync_enable = atoi(value);

    // HOST
    dtp_setting.host_drop = 1;
    if(GetEnv("HOST","host.drop",value) > 0)
        dtp_setting.host_drop = atoi(value);
    dtp_setting.host_drop_thres = 100;
    if(GetEnv("HOST","host.drop.thres",value) > 0)
        dtp_setting.host_drop_thres = atoi(value);
    dtp_setting.host_sync_thres = 100;
    if(GetEnv("HOST","host.sync.thres",value) > 0)
        dtp_setting.host_sync_thres = atoi(value);

    dt_info(TAG, "update dtp setting ok \n");

    return 0;
}
