/*
* mi_fd.h- Sigmastar
*
* Copyright (C) 2018 Sigmastar Technology Corp.
*
* Author: XXXX <XXXX@sigmastar.com.cn>
*
* This software is licensed under the terms of the GNU General Public
* License version 2, as published by the Free Software Foundation, and
* may be copied, distributed, and modified under those terms.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*/
#ifndef __MI_FD_H__
#define __MI_FD_H__

#include "mid_common.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum _MI_RET_E
{
    /*MI_FDFR*/
    MI_FDFR_RET_SUCCESS                     = 0x00000000, /* FDFR API execution success */
    MI_FDFR_RET_INIT_ERROR                  = 0x10000601,   /*FDFR init error*/
    MI_FDFR_RET_IC_CHECK_ERROR              = 0x10000602,   /*Incorrect platform check for FDFR*/
    MI_FDFR_RET_INVALID_HANDLE              = 0x10000603,   /*Invalid FDFR handle*/
    MI_FDFR_RET_INVALID_PARAMETER           = 0x10000604,   /*Invalid FDFR parameter*/
    MI_FDFR_RET_FD_ENABLE_ERROR             = 0x10000605,   /*FD enable error*/
    MI_FDFR_RET_FR_ENABLE_ERROR             = 0x10000606,   /*FR enable error*/
    MI_FDFR_RET_FR_GET_FEATURE_DATA_ERROR   = 0x10000607,   /*FR get feature data error*/
    MI_FDFR_RET_FR_SET_FEATURE_DATA_ERROR   = 0x10000608,   /*FR set feature data error*/
    MI_FDFR_RET_IN_IMAGE_ERROR              = 0x10000609   /*Input image error*/
} MI_RET;


typedef enum
{
    FD_OPTION_DETECT_MODE   ,
    FD_OPTION_FACE_WIDTH    ,
    FD_OPTION_PARTIAL_WIDTH ,
    FD_OPTION_FACE_DIRECTION,
    FD_OPTION_NUM
} FDOption_e;

typedef     enum
{
    FULL_MODE = 0,
    TRACK_MODE,
    PARTIAL_MODE,
    NUM_MODE
} FDDetectMode_e;

typedef struct
{
    MI_S32 store_idx;
    MI_U32 percentage;
    MI_S8 name[32];
} FRFaceInfo_t;

typedef struct
{
    MI_S16    posx;
    MI_S16    posy;
    MI_S16    posw;
    MI_S16    posh;
	MI_S16    rotate;
	MI_S16    conf;
} FacePos_t;

typedef struct _MI_FDFR_RECT
{
    MI_S16 sx;
    MI_S16 sy;
    MI_S16 ex;
    MI_S16 ey;
} MI_FDFR_RECT;

typedef void* FD_HANDLE;
typedef void* FR_HANDLE;
#define FD_NUM_OF_FACE_UNIT (10)
#define FR_UNKNOWN_NAME "UNKNOWN NAME"
/***********************************FD API define  *****************************************/
/**
 * ��ʼ�� FD ��
 * inImgW:  ����Դ��
 * inImhH:  ����Դ��
 * return:  FD �� handle���
 */
FD_HANDLE MI_FD_Init(MI_S32 inImgW, MI_S32 inImhH);

/**
 * �˳��⺯�����ͷ��ڴ档
 * fdHandle:    FD �� handle ���
 * return:  ��
 */
void MI_FD_Uninit(FD_HANDLE fdHandle);

/**
 * ʹ���������
 * fdHandle:    FD �� handle ���
 * bEnable:     ʹ�ܱ�־
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FD_EnableFD(FD_HANDLE fdHandle, MI_S32 bEnable);

/**
 * ��������ʶ�����
 * fdHandle:    FD �� handle ���
 * opt:         ����ѡ��
 * val:         ����ֵ
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FD_SetOption(FD_HANDLE fdHandle, FDOption_e opt, MI_S32 val);

/**
 * ��ʼ��������ʶ��ͼ��֡
 * fdHandle:    FD �� handle ���
 * yFrame:      ͼ�� YUV �е� y��������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_S32 MI_FD_Run(FD_HANDLE fdHandle, const MI_U8 *yFrame);

/**
 * ��ȡ���������
 * fdHandle:    FD �� handle ���
 * out_facepos: ����λ�ýṹ��
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_S32 MI_FD_GetFaceInfo(FD_HANDLE fdHandle, FacePos_t **out_facepos);


/***********************************FR API define  *****************************************/
/**
 * ��ʼ�� FR ��
 * inImgW:  ����Դ��
 * inImhH:  ����Դ��
 * return:  FD �� handle���
 */
FR_HANDLE MI_FR_Init(MI_S32 inImgW, MI_S32 inImgH);

/**
 * �˳��⺯�����ͷ��ڴ档
 * frHandle:    FR �� handle ���
 * return:  ��
 */
void MI_FR_Uninit(FR_HANDLE frHandle);

/**
 * ʹ������ʶ��
 * fdHandle:    FR �� handle ���
 * bEnable:     ʹ�ܱ�־
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_EnableFR(FR_HANDLE frHandle, MI_S32 bEnable);

/**
 * ��ȡ����ʶ��Ľ����Ϣ
 * fdHandle:    FR �� handle ���
 * fd_num:      ���ɻ�ȡ��������Ϣ�������ܳ���FD_NUM_OF_FACE_UNIT
 * faceInfo:    ������Ϣ����ָ��
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_S32 MI_FR_GetFRInfo(FR_HANDLE frHandle, int FD_NUM, FRFaceInfo_t *faceInfo);

/**
 * ��������������Ϣ�����ݿ�
 * idx:    �������������ݿ��������
 * feat_data:     ������������
 * feat_name:    ��������������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_SetFeatureData(MI_S16 idx, MI_S8* feat_data, MI_S8* feat_name);

/**
 * ��ȡ���ݿ��е���������
 * idx:    �������������ݿ��������
 * feat_data:     ������������
 * feat_name:    ��������������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_GetFeatureData(MI_S16 idx, MI_S8* feat_data, MI_S8* feat_name);

/**
 * ��ȡ�����������ݵĴ�С
 * return:      ÿ�������������ݵĴ�С
 */
MI_S32 MI_FR_GetFeatureSizes();

/**
 * ��pgm��ʽ��ͼƬ������������
 * filename:    ͼƬ�ļ���
 * store_idx:   �������������ݿ��������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_CalFeatureFromImg(MI_S8* filename, MI_S32 store_idx);

/**
 * ��ͼ��YUV�е�y��������������������
 * imgPtr:  y��������buffer��ָ��
 * width:    ͼ��Ŀ��
 * height:   ͼ��ĸ߶�
 * store_idx:   �������������ݿ��������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_CalFeatureFromRawY(MI_U8* imgPtr, MI_S32 width, MI_S32 height, MI_S32 store_idx);

/**
 * ��ͼ��YUV�е�y��������ͼ�����
 * imgPtr:  y��������buffer��ָ��
 * width:    ͼ��Ŀ��
 * height:   ͼ��ĸ߶�
 * prect_img_center:   ����ͼƬ�е�λ��
 * return:   ͼ�����
 */
MI_S32 MI_FR_CalcImageScore(MI_U8* imgPtr, MI_S32 width, MI_S32 height, MI_FDFR_RECT* prect_img_center);

/**
 * Set FR mode.
 * mode
     0 : Low accuracy but speed is fast.
     1 : Middle accuracy but speed is middle.
     2 : High accuracy but speed is slow. (default)
 * return:    MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_S32 MI_FR_SetFrMode(MI_S32 mode);

/**
 * To set a threshold to decide whether do FR or not.
 * face_width
  Setting a threshold, If the Face width of Face is bigger than this threshold,
  the process will do FR. Otherwise, the process will still do FD.
 * return:    MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_S32 MI_FR_SetFrFaceWidth(MI_S32 face_width);

#ifdef __cplusplus
}
#endif

#endif //__MI_FD_H__
