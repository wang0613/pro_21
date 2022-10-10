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
        //从前向后copy
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
        //将5 放到 7的位置，
        //4 放到 6的位置
        //3 翻到 5的位置

        while (count--)
        {
            //先找到最后-1的字节位置
            *((char*)dest+count) = *((char*)src+count);
        }
    }


    return ret;
}

int main() {

//    int arr1[] = {1, 2, 3, 4, 5};
//    int arr2[5] = {0};

    //strcpy()；
//    strcpy(arr2,arr1);

    //copy  arr1  arr2
//    memcpy(arr2, arr1, sizeof(arr1));
//    struct S s1[2] = {{"张三", 20},
//                     {"李思", 22}};
//    struct S s2[2] = {{},
//                      {}};

//    my_memcpy(s2, s1, sizeof(s1));

    //1 2 1 2 3 4 5 8 9 10 移动
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    //memcpy()；做不到重叠copy
//    memcpy(arr+2,arr,20);

    //memmove(); 可以做到重叠copy  移动5个数字20个字节
    my_memmove(arr+2,arr,20);

    //c语言标准：memcpy()；可以copy不重叠就可以了 但是在vs2013环境下，可以处理重叠copy(clion中不行)
    //不符合c语言标准，建议使用memmove();


    //memcmp();
    return 0;
}
