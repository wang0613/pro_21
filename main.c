#include <stdio.h>
#include <string.h>
#include <assert.h>

//memcpy();
//memmove();
//memset();
//memcmp();

struct S {
    char name[40];
    int age;
};

//void *my_memcpy(void *dest, const void *src, size_t num) {
//
//    char* ret = dest;
//    assert(dest&&src);
//    while (num--)
//    {
//        *(char*)dest = *(char*)src;
//        ++(char*)dest;
//        ++(char*)src;
//
//    }
//
//    return ret;
//}

void *my_memmove(void *dest, const void *src, size_t count)
{
    assert(dest!=NULL);
    assert(src!=NULL);
    void *ret = dest;

    //dest 1 2  src 3 4 5
    //1 2 3 4 5
    //3 4 5 4 5
    if(dest < src)
    {
        //��ǰ���copy
        while (count--)
        {
            *(char*)dest = *(char*)src;
            (char*)dest++;
            (char*)src++;
        }

    }else{
        //src1 2 dest3 4 5 6 7 8
        //1 2 3 4 5 6 7 8
        //1 2 1 2 3 4 5 8
        //��5 �ŵ� 7��λ�ã�
        //4 �ŵ� 6��λ��
        //3 ���� 5��λ��

        while (count--)
        {
            //���ҵ����-1���ֽ�λ��
            *((char*)dest+count) = *((char*)src+count);
        }
    }


    return ret;
}

int main() {

//    int arr1[] = {1, 2, 3, 4, 5};
//    int arr2[5] = {0};

    //strcpy()��
//    strcpy(arr2,arr1);

    //copy  arr1  arr2
//    memcpy(arr2, arr1, sizeof(arr1));
//    struct S s1[2] = {{"����", 20},
//                     {"��˼", 22}};
//    struct S s2[2] = {{},
//                      {}};

//    my_memcpy(s2, s1, sizeof(s1));

    //1 2 1 2 3 4 5 8 9 10 �ƶ�
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    //memcpy()���������ص�copy
//    memcpy(arr+2,arr,20);

    //memmove(); ���������ص�copy  �ƶ�5������20���ֽ�
    my_memmove(arr+2,arr,20);

    //c���Ա�׼��memcpy()������copy���ص��Ϳ����� ������vs2013�����£����Դ����ص�copy(clion�в���)
    //������c���Ա�׼������ʹ��memmove();


    //memcmp();
    return 0;
}
