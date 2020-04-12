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
#ifndef __MI_VI_H__
#define __MI_VI_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "mi_vi_type.h"

/**
 *  ���� VI �豸����
 *  pstAttr:        VI �豸����ָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_SetDevAttr(const ViDevAtrr_t *pstAttr);

/**
 *  ��ȡ VI �豸����
 *  pstAttr:        VI �豸����ָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetDevAttr(ViDevAtrr_t *pstAttr);

/**
 *  ���� VI ͨ������
 *  ViChn:          VI ͨ����
 *  pstAttr:        VI ͨ������ָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_SetChnAttr(VI_CHN ViChn, const ViChnAttr_t *pstAttr);

/**
 *  ��ȡ VI ͨ������
 *  ViChn:          VI ͨ����
 *  pstAttr:        VI ͨ������ָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetChnAttr(VI_CHN ViChn, ViChnAttr_t *pstAttr);


/**
 *  ���� VI ͨ��
 *  ViChn:          VI ͨ����
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_EnableChn(VI_CHN ViChn);

/**
 *  ���� VI ͨ��
 *  ViChn:          VI ͨ����
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_DisableChn(VI_CHN ViChn);

/**
 *  ��ȡ VI �ɼ���ͼ��
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetFrame(VI_CHN ViChn, VideoFrameInfo_t *pstFrameInfo);

/**
 *  ��ȡ VI �ɼ���ͼ��
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  u32MilliSec:    ��ʱʱ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetFrameTimeOut(VI_CHN ViChn, VideoFrameInfo_t *pstFrameInfo, U32 u32MilliSec);

/**
 *  �ͷ� VI ͼ��������ռ�Ļ���
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_ReleaseFrame(VI_CHN ViChn, VideoFrameInfo_t *pstFrameInfo);

/**
 *  ��ȡ VI �ɼ���ͼ��
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetFrameEx(VI_CHN ViChn, VideoFrameInfoEx_t *pstFrameInfo);

/**
 *  ��ȡ VI �ɼ���ͼ��
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  u32MilliSec:    ��ʱʱ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetFrameTimeOutEx(VI_CHN ViChn, VideoFrameInfoEx_t *pstFrameInfo, U32 u32MilliSec);

/**
 *  �ͷ� VI ͼ��������ռ�Ļ���
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_ReleaseFrameEx(VI_CHN ViChn, VideoFrameInfoEx_t *pstFrameInfo);

/**
 *  �ͷŶ��VI ͼ��������ռ�Ļ��棬���MI�����л���yuv���ݣ�Ҳ���ͷŵ���ֻ�������µ�restFrameNum֡����
 *  ViChn:          VI ͨ����
 *  pstFrameInfo:   VI ֡��Ϣ�ṹָ��
 *  restFrameNum:   ��Ҫ�ڻ�����������֡
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_ReleaseMutiFrame(VI_CHN ViChn, VideoFrameInfo_t *pstFrameInfo, U32 restFrameNum);

/**
 *
 */
MI_RET MI_VI_SetSensorFrameRate(F32 frameRate);
MI_RET MI_VI_GetSensorFrameRate(F32 *frameRate);

/*
* ����vi 1/2��ȡ����
*  ViChn:		   VI ͨ����
*  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ?*/
MI_RET MI_VI_FlashTrigger(VI_CHN ViChn);

/**
 *  ����viͼ��������
 *  ViChn:          VI ͨ����
 *  depth:          ��ȡ�Ϊ0ʱ��Ч����ʹ��Ĭ��ֵ
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_SetFrameDepth(VI_CHN ViChn, U32 depth);

/**
 *  ��ȡviͼ��������
 *  ViChn:          VI ͨ����
 *  depth:          ��ȡ�
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_GetFrameDepth(VI_CHN ViChn, U32 *pDepth);

MI_RET MI_VI_SetRotate(S32 Rotation);

/*����ü�����*/
MI_RET MI_ISP_SetInputCrop(U32 nChannel, Rect_t CropRect);
MI_RET MI_ISP_GetInputCrop(U32 nChannel, Rect_t *pCropRect);
/*��������*/
MI_RET MI_ISP_SetDigitalZoom(U32 nChannel, S32 Width, S32 Height);
MI_RET MI_ISP_GetDigitalZoom(U32 nChannel, S32 *pWidth, S32 *pHeight);
/*�ų�����*/
MI_RET MI_ISP_SetExclusionRect(U32 nChannel, Rect_t ExclusionRect);
MI_RET MI_ISP_GetExclusionRect(U32 nChannel, Rect_t *pExclusionRect);

/**
 * ����cropͨ������
 *  ViChn:          VI ͨ����
 *  pRect:          ����
 *  return:         MI_RET_SUCCESS�ɹ���MI_RET_FAILʧ��
 */
MI_RET MI_VI_SetChnCrop(VI_CHN ViChn, Rect_t *pRect);
MI_RET MI_VI_GetFrameTimeOutForSandBox(VI_CHN ViChn, VideoFrameInfo_t *pstFrameInfo, S32 milliSec);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MI_VI_H__ */



