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
    int32_t store_idx;
    uint32_t percentage;
    int8_t name[32];
} FRFaceInfo_t;

typedef struct
{
    int16_t    posx;
    int16_t    posy;
    int16_t    posw;
    int16_t    posh;
	int16_t    rotate;
	int16_t    conf;
} FacePos_t;

typedef struct _MI_FDFR_RECT
{
    int16_t sx;
    int16_t sy;
    int16_t ex;
    int16_t ey;
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
FD_HANDLE MI_FD_Init(int32_t inImgW, int32_t inImhH);

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
MI_RET MI_FD_EnableFD(FD_HANDLE fdHandle, int32_t bEnable);

/**
 * ��������ʶ�����
 * fdHandle:    FD �� handle ���
 * opt:         ����ѡ��
 * val:         ����ֵ
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FD_SetOption(FD_HANDLE fdHandle, FDOption_e opt, int32_t val);

/**
 * ��ʼ��������ʶ��ͼ��֡
 * fdHandle:    FD �� handle ���
 * yFrame:      ͼ�� YUV �е� y��������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
int32_t MI_FD_Run(FD_HANDLE fdHandle, const uint8_t *yFrame);

/**
 * ��ȡ���������
 * fdHandle:    FD �� handle ���
 * out_facepos: ����λ�ýṹ��
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
int32_t MI_FD_GetFaceInfo(FD_HANDLE fdHandle, FacePos_t **out_facepos);


/***********************************FR API define  *****************************************/
/**
 * ��ʼ�� FR ��
 * inImgW:  ����Դ��
 * inImhH:  ����Դ��
 * return:  FD �� handle���
 */
FR_HANDLE MI_FR_Init(int32_t inImgW, int32_t inImgH);

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
MI_RET MI_FR_EnableFR(FR_HANDLE frHandle, int32_t bEnable);

/**
 * ��ȡ����ʶ��Ľ����Ϣ
 * fdHandle:    FR �� handle ���
 * fd_num:      ���ɻ�ȡ��������Ϣ�������ܳ���FD_NUM_OF_FACE_UNIT
 * faceInfo:    ������Ϣ����ָ��
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
int32_t MI_FR_GetFRInfo(FR_HANDLE frHandle, int FD_NUM, FRFaceInfo_t *faceInfo);

/**
 * ��������������Ϣ�����ݿ�
 * idx:    �������������ݿ��������
 * feat_data:     ������������
 * feat_name:    ��������������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_SetFeatureData(int16_t idx, int8_t* feat_data, int8_t* feat_name);

/**
 * ��ȡ���ݿ��е���������
 * idx:    �������������ݿ��������
 * feat_data:     ������������
 * feat_name:    ��������������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_GetFeatureData(int16_t idx, int8_t* feat_data, int8_t* feat_name);

/**
 * ��ȡ�����������ݵĴ�С
 * return:      ÿ�������������ݵĴ�С
 */
int32_t MI_FR_GetFeatureSizes();

/**
 * ��pgm��ʽ��ͼƬ������������
 * filename:    ͼƬ�ļ���
 * store_idx:   �������������ݿ��������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_CalFeatureFromImg(int8_t* filename, int32_t store_idx);

/**
 * ��ͼ��YUV�е�y��������������������
 * imgPtr:  y��������buffer��ָ��
 * width:    ͼ��Ŀ��
 * height:   ͼ��ĸ߶�
 * store_idx:   �������������ݿ��������
 * return:      MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
MI_RET MI_FR_CalFeatureFromRawY(uint8_t* imgPtr, int32_t width, int32_t height, int32_t store_idx);

/**
 * ��ͼ��YUV�е�y��������ͼ�����
 * imgPtr:  y��������buffer��ָ��
 * width:    ͼ��Ŀ��
 * height:   ͼ��ĸ߶�
 * prect_img_center:   ����ͼƬ�е�λ��
 * return:   ͼ�����
 */
int32_t MI_FR_CalcImageScore(uint8_t* imgPtr, int32_t width, int32_t height, MI_FDFR_RECT* prect_img_center);

/**
 * Set FR mode.
 * mode
     0 : Low accuracy but speed is fast.
     1 : Middle accuracy but speed is middle.
     2 : High accuracy but speed is slow. (default)
 * return:    MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
int32_t MI_FR_SetFrMode(int32_t mode);

/**
 * To set a threshold to decide whether do FR or not.
 * face_width
  Setting a threshold, If the Face width of Face is bigger than this threshold,
  the process will do FR. Otherwise, the process will still do FD.
 * return:    MI_FDFR_RET_SUCCESS�ɹ���MI_FDFR_RET_FAILʧ��
 */
int32_t MI_FR_SetFrFaceWidth(int32_t face_width);

#ifdef __cplusplus
}
#endif

#endif //__MI_FD_H__
