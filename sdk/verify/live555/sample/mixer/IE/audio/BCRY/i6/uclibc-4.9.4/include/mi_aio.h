/* Copyright (c) 2018-2019 Sigmastar Technology Corp.
 All rights reserved.
  
  Unless otherwise stipulated in writing, any and all information contained
 herein regardless in any format shall remain the sole proprietary of
 Sigmastar Technology Corp. and be kept in strict confidence
 (??Sigmastar Confidential Information??) by the recipient.
 Any unauthorized act including without limitation unauthorized disclosure,
 copying, use, reproduction, sale, distribution, modification, disassembling,
 reverse engineering and compiling of the contents of Sigmastar Confidential
 Information is unlawful and strictly prohibited. Sigmastar hereby reserves the
 rights to any and all damages, losses, costs and expenses resulting therefrom.
*/
#ifndef __MI_AIO_H__
#define __MI_AIO_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include "mi_common.h"
#include "mi_audio_type.h"

/*this is used just for single audio case,no video,no osd,no isp etc..*/
MI_RET MI_Audio_Init();
MI_RET MI_Audio_Exit();
/*end*/
/**
 *  ����AI�豸����
 *  AudioDevId:         ��Ƶ�豸���
 *  pstAttr:                ��Ƶ�豸����
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_SetDevAttr(AUDIO_DEV AudioDevId, const AioDevAttr_t *pstAttr);

/**
 *  ��ȡAI�豸����
 *  AudioDevId:         ��Ƶ�豸���
 *  pstAttr:                ��Ƶ�豸����
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetDevAttr(AUDIO_DEV AudioDevId, AioDevAttr_t *pstAttr);


/**
 *  ����AIͨ������
 *  AiChn:                 ��Ƶͨ��
 *  pstChnParam        ��Ƶͨ������
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_AI_SetChnAttr(AIO_CHN AiChn, const AioChnAttr_t* pstChnParam);

/**
 * ��ȡͨ������
 *  AiChn:            ��Ƶͨ����
 *  pstChnParam   ��Ƶͨ������
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetChnAttr(AIO_CHN AiChn, AioChnAttr_t* pstChnParam);


/**
 *  ����AI�豸
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_Enable(AUDIO_DEV AudioDevId);

/**
 *  ����AI�豸
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_Disable(AUDIO_DEV AudioDevId);

/**
 *  ����AIͨ��
 *  AudioDevId:         ��Ƶ�豸���
 *  AiChn:              ��Ƶͨ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_EnableChn(AUDIO_DEV AudioDevId, AIO_CHN AiChn);

/**
 *  ����AIͨ��
 *  AudioDevId:         ��Ƶ�豸���
 *  AiChn:              ��Ƶͨ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableChn(AUDIO_DEV AudioDevId, AIO_CHN AiChn);

/**
 *  ��ȡ��Ƶ����ͨ���Ŷ�Ӧ���豸�ļ����
 *  AiChn:              ��Ƶ����ͨ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetFd(AIO_CHN AiChn);

/**
 *  ����AI�豸����
 *  AudioDevId:         ��Ƶ�豸���
 *  sVolume:            ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_SetVolume(AUDIO_DEV AudioDevId, S32 sVolume);

/**
 *  ��ȡAI�豸����
 *  AudioDevId:         ��Ƶ�豸���
 *  sVolume:            ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetVolume(AUDIO_DEV AudioDevId, S32 *sVolume);

/**
*  ����AI�ز���
*  AudioDevId:         ��Ƶ�豸���
*  AiChn:              ��Ƶͨ����
*  enOutSampleRate:    ������
*  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
*/

MI_RET MI_AI_EnableReSmp(AUDIO_DEV AudioDevId, AIO_CHN AiChn, AudioSampleRate_e enOutSampleRate);

/**
 *  ����AI����״̬
 *  AudioDevId:         ��Ƶ�豸���
 *  ptMute:             ���ýṹ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_SetMute(AUDIO_DEV AudioDevId, AudioMute_t *ptMute);

/**
 *  ��ȡAI����״̬
 *  AudioDevId:         ��Ƶ�豸���
 *  ptMute:             ���ýṹ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetMute(AUDIO_DEV AudioDevId, AudioMute_t *ptMute);

/**
 *  ����AI�ز���
 *  AudioDevId:         ��Ƶ�豸���
 *  AiChn:              ��Ƶͨ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableReSmp(AUDIO_DEV AudioDevId, AIO_CHN AiChn);


/**
 *  ������Ƶ����
 *  AudioDevId:         ��Ƶ�豸���
 *  AiChn:              ��Ƶͨ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_AI_StartFrame(AUDIO_DEV AudioDevId, AIO_CHN AiChn);


/**
 *  ��ȡAI����֡
 *  AudioDevId:         ��Ƶ�豸���
 *  AiChn:              ��Ƶͨ����
 *  pstFrm:             ��Ƶ����֡
 *  sMilliSec :         >0 �ȴ�sMillisec
 *            :         -1 Ĭ�ϵȴ�INFINITE_WAIT
 *            :         0  ���ȴ�
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetFrame(AUDIO_DEV AudioDevId, AIO_CHN AiChn, AudioFrame_t *pstFrm, S32 sMilliSec);

/**
 *  �ͷ�AI����֡
 *  AudioDevId:         ��Ƶ�豸���
 *  AiChn:              ��Ƶͨ����
 *  pstFrm:             ��Ƶ����֡
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_ReleaseFrame(AUDIO_DEV AudioDevId, AIO_CHN AiChn, AudioFrame_t *pstFrm);

/**
 *  ����������
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_EnableAEC(AUDIO_DEV AudioDevId);

/**
 *  ����������
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableAEC(AUDIO_DEV AudioDevId);

/**
 *  ������������
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_EnableANR(AUDIO_DEV AudioDevId);

/**
 *  ������������
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableANR(AUDIO_DEV AudioDevId);

/**
 *  �����Զ�����
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_EnableAGC(AUDIO_DEV AudioDevId);

/**
 *  �����Զ�����
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableAGC(AUDIO_DEV AudioDevId);

/**
 *  ���ý�����
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_EnableWNR(AUDIO_DEV AudioDevId);

/**
 *  ���ý�����
 *  AudioDevId:         ��Ƶ�豸���
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableWNR(AUDIO_DEV AudioDevId);

/**
 *  ���þ���
 *  AudioDevId:         ��Ƶ�豸���
 *  return:                MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_EnableEQ(AUDIO_DEV AudioDevId);

/**
 *  ���þ���
 *  AudioDevId:         ��Ƶ�豸���
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_DisableEQ(AUDIO_DEV AudioDevId);

/**
 *  ����AI������ǿ����
 *  AudioDevId:         ��Ƶ�豸���
 *  AI_VQE_CONFIG:  ������ǿ�ṹ��
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_SetVqeAttr(AUDIO_DEV AudioDevId, AI_VQE_CONFIG *pVqeConfig);

/**
 *  ��ȡAI������ǿ����
 *  AudioDevId:         ��Ƶ�豸���
 *  pVqeConfig:         ������ǿ�ṹ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetVqeAttr(AUDIO_DEV AudioDevId, AI_VQE_CONFIG *pVqeConfig);

/**
 *  ��ȡAI ʵʱ����
 *  AudioDevId:         ��Ƶ�豸���
 *  pRtVolume:          ʵʱ����
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetRTVolume(AUDIO_DEV AudioDevId, U16 *pRtVolume);

/**
 *  ����AI ADC
 *  AudioDevId:         ��Ƶ�豸���
 *  pAdc:                  adc����
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_SetADC(AUDIO_DEV AudioDevId, AiAdcConfig_t *pAdc);

/**
 *  ��ȡAI ADC����
 *  AudioDevId:         ��Ƶ�豸���
 *  pAdc:                  adc����
 *  return:                 MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AI_GetADC(AUDIO_DEV AudioDevId, AiAdcConfig_t *pAdc);

/**
 *  ����AO�豸����
 *  AudioDevId:         ��Ƶ�豸���
 *  pstAttr:            ��Ƶ�豸����
 *  return:
 */
MI_RET MI_AO_SetDevAttr(AUDIO_DEV AudioDevId, const AioDevAttr_t *pstAttr);

/**
 *  ��ȡAO�豸����
 *  AudioDevId:         ��Ƶ�豸���
 *  pstAttr:            ��Ƶ�豸����
 *  return:
 */
MI_RET MI_AO_GetDevAttr(AUDIO_DEV AudioDevId, AioDevAttr_t *pstAttr);

/**
 *  ����AOͨ������
 *  AoChn:         ��Ƶ�豸���
 *  pstChnParam   ��Ƶͨ������
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_SetChnAttr(AIO_CHN AoChn, const AioChnAttr_t* pstChnParam);

/**
 * ��ȡAOͨ������
 *  AoChn:            ��Ƶͨ����
 *  pstChnParam   ��Ƶͨ������
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */

MI_RET MI_AO_GetChnAttr(AIO_CHN AoChn, AioChnAttr_t* pstChnParam);


/**
 *  ����AO�豸
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_Enable(AUDIO_DEV AudioDevId);

/**
 *  ����AO�豸
 *  AudioDevId:         ��Ƶ�豸���
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_Disable(AUDIO_DEV AudioDevId);

/**
 *  ����AOͨ��
 *  AudioDevId:         ��Ƶ�豸���
 *  AoChn:              ��Ƶͨ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_EnableChn(AUDIO_DEV AudioDevId, AIO_CHN AoChn);

/**
 *  ����AOͨ��
 *  AudioDevId:         ��Ƶ�豸���
 *  AoChn:              ��Ƶͨ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_DisableChn(AUDIO_DEV AudioDevId, AIO_CHN AoChn);

/**
 *  ����AO����
 *  AudioDevId:         ��Ƶ�豸���
 *  sVolume:        ����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_SetVolume(AUDIO_DEV AudioDevId, S32 sVolume);

/**
 *  ��ȡAO����
 *  AudioDevId:         ��Ƶ�豸���
 *  sVolume:       �������ݵ�ַ
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_GetVolume(AUDIO_DEV AudioDevId, S32 *sVolume);

/**
 *  ����AO����״̬
 *  AudioDevId:         ��Ƶ�豸���
 *  ptMute:             ���ýṹ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_SetMute(AUDIO_DEV AudioDevId, AudioMute_t *ptMute);

/**
 *  ��ȡAO����״̬
 *  AudioDevId:         ��Ƶ�豸���
 *  ptMute:             ���ýṹ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_GetMute(AUDIO_DEV AudioDevId, AudioMute_t *ptMute);


/**
 *  ������Ƶ��AO
 *  AudioDevId:         ��Ƶ�豸���
 *  AoChn:                ��Ƶͨ����
 *  pFrame:               ��Ƶ����֡
 *  sBlock:                -1,����;��0��������
 *  pAoCB:                �������ص�����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AO_SendFrame(AUDIO_DEV AudioDevId, AIO_CHN AoChn, AudioFrame_t *pFrame, S32 sBlock, AdecCallback_t *pAoCB);


#ifdef __cplusplus
}
#endif //__cplusplus
#endif // __MI_AIO_H__

