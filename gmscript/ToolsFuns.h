#pragma once
//���ߺ��� ���ݸ��� 
//������Ŀ������ ����Ŀ�꿪ʼλ�� ��Դ���� ������Դ��ʼλ�� ���Ƴ���
//����Ҳ����ʵ����[]������Ķ���
//���أ�ʵ�ʸ��Ƶ�����
template<class DSTArrayType,class SRCArrayType>
uint64_t dmemcpy(DSTArrayType &dst, uint64_t dstart, SRCArrayType &src, uint64_t sstart, uint64_t len)
{
	uint64_t ret = 0; //���Ƶ�����
	try
	{
		for (int i = 0; i < len; i++)
		{
			dst[dstart + i] = src[sstart + i];//����
			ret++; //����+1
		}
	}
	catch (...)
	{
		return ret;//�������κ��쳣ʱ,���ص�ǰ���Ƶ�����
	}
	return ret;
}