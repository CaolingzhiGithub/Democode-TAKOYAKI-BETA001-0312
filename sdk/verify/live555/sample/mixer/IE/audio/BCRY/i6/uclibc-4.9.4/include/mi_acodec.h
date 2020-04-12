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
#ifndef __MI_ACODEC_H__
#define __MI_ACODEC_H__
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#include "mi_audio_type.h"

/**
 *  ������Ƶ����ͨ��
 *  AeChn:              ��Ƶ����ͨ��
 *  pstAttr:            ��Ƶ�豸����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AENC_CreateChn(AENC_CHN AeChn, AencChnAttr_t *pstAttr);

/**
 *  ������Ƶ����ͨ��
 *  AeChn:              ��Ƶ����ͨ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AENC_DestroyChn(AENC_CHN AeChn);

/**
 *  ��ʼ��ȡ��Ƶ����������
 *  AeChn:              ��Ƶ����ͨ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AENC_StartStream(AENC_CHN AeChn);

/**
 *  ��ȡ��Ƶ����������
 *  AeChn:              ��Ƶ����ͨ��
 *  pstStream :         ��Ƶ������
 *  sMilliSec :         >0 �ȴ�sMillisec
 *            :         -1 Ĭ�ϵȴ�INFINITE_WAIT
 *            :         0  ���ȴ�
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AENC_GetStream(AENC_CHN AeChn, AudioStream_t *pstStream, S32 sMilliSec);

/**
 *  �ͷ���Ƶ����������
 *  AeChn:              ��Ƶ����ͨ��
 *  pstStream :         ��Ƶ������
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_AENC_ReleaseStream(AENC_CHN AeChn, AudioStream_t *pstStream);

/**
 *  ��ȡ��Ƶ����ͨ���Ŷ�Ӧ���豸�ļ����
 *  AeChn:              ��Ƶ����ͨ��
 *  return:             FD���
 */
S32 MI_AENC_GetFd(AENC_CHN AeChn);

/**
 *  ������Ƶ����ͨ��
 *  AdChn:              ��Ƶ����ͨ��
 *  pstAttr:            ��Ƶ�豸����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_ADEC_CreateChn(ADEC_CHN AdChn, AdecChnAttr_t *pstAttr);

/**
 *  ������Ƶ����ͨ��
 *  AdChn:              ��Ƶ����ͨ��
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_ADEC_DestroyChn(ADEC_CHN AdChn);

/**
 *  ������Ƶ��������֡
 *  AdChn:              ��Ƶ����ͨ��
 *  pstStream:          ��Ƶ����������
 *  sBlock:             -1,����;��0��������
 *  pAdecCB             �������ص�����
 *  return:             MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_ADEC_SendStream(ADEC_CHN AdChn, AudioStream_t *pstStream, S32 sBlock, AdecCallback_t *pAdecCB);


#ifdef __cplusplus
}
#endif //__cplusplus
#endif //__MI_ACODEC_H__

