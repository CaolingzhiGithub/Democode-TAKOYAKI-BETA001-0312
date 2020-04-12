/*    filename PacketCore.h
*   Description:
*    Copyright(C):    2016 Mstar Semiconductor
*    Version:        V 1.0
*    Author:        fisher.yang
*    Created:        2016-08-09
*/


#ifndef __PACKETCORE_H__
#define __PACKETCORE_H__

#include "mid_common.h"

#include "List.h"
#include "MyMutex.h"


#if 0
typedef struct _PacketCoreBlock
{
    HANDLE handle;

    MI_S8* ptr;

    MI_U32 length;

    MI_U32 size;

    struct list_head Plist;
}PACKETCOREBLOCK;
#endif

class CPacket {

public:
    MI_U32    PutBuffer(MI_U32 dwLength);
    MI_U8 *    GetBuffer();
    MI_U32    GetLength();                    //ȡ���ݳ���
    MI_U32    Release();
    MI_U32    AddRef();
    MI_S32    GetRef();

private:
    MI_U8 *    m_pBuffer;        //����ָ��
    MI_U32    m_Length;        //���ݳ���
    volatile MI_S32    m_RefCount;        //���ü���
    MyMutex    m_Mutex;        //������

    struct list_head packetlist;

    CPacket();
    ~CPacket();

    friend class PacketModule;
};

#endif

