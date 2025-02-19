#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void shuzu_store_up_tranditional(int arr_1[],int changdu){
    for (int i=0;i<changdu-1;i++){
        for (int j=0;j<changdu-1-i;j++){
            if (arr_1[j]>arr_1[j+1]){
                int a=arr_1[j+1];
                arr_1[j+1]=arr_1[j];
                arr_1[j]=a;
            }
        }
    }
}

int gongyinshu_muti_maxism(int hang,int lie,int weizhi,int arr_1[hang][lie]){
    int arr_check[lie];
    for (int i=0;i<lie;i++){
        if (arr_1[weizhi-1][i]>0){
            arr_check[i]=arr_1[weizhi-1][i];
        }
        else {
            arr_check[i]=-arr_1[weizhi-1][i];
        }
    }
    shuzu_store_up_tranditional(arr_check,lie);
    int minimal=0;
    for (int i=0;i<lie;i++){
        if (arr_check[i]!=0){
            minimal=arr_check[i];
            break;
        }
    }
    if (minimal==0){
        return 1;
    }
    int flag=0;
    int out_put=1;
    for (int i=minimal;i>0;i--){
        if (minimal%i==0){
            flag=0;
            for (int j=0;j<lie;j++){
                if (arr_check[j]%i==0){
                    flag++;
                }
            }
            if (flag==lie){
                out_put=i;
                return out_put;
            }
        }
    }
    return out_put;
}

void jvzhen_print (int hang,int lie,int arr[hang][lie]){
    for (int i=0;i<hang;i++){
        for (int j=0;j<lie;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int weishu_shibie (int a){
    int out_put=0;
    a=abs(a);
    if (a<10){
        out_put=0;
        return out_put;
    }
    if (a/10<10){
        out_put=1;
        return out_put;
    }
    if (a/100<10){
        out_put=2;
        return out_put;
    }
    if (a/1000<10){
        out_put=3;
        return out_put;
    }
    if (a/10000<10){
        out_put=4;
        return out_put;
    }
    if (a/100000<10){
        out_put=5;
        return out_put;
    }
    if (a/1000000<10){
        out_put=6;
        return out_put;
    }
    if (a/10000000<10){
        out_put=7;
        return out_put;
    }
    return out_put;
}

void jvzhen_print_improved (int hang,int lie,int arr[hang][lie]){
    int maxism=0;
    int minimal=0;
    for (int i=0;i<hang;i++){
        for (int j=0;j<lie;j++){
            if (arr[i][j]>maxism){
                maxism=arr[i][j];
            }
            if (arr[i][j]<minimal){
                minimal=arr[i][j];
            }
        }
    }
    int wei=0;
    if (weishu_shibie(maxism)>weishu_shibie(minimal)){
        wei=weishu_shibie(maxism);
    }
    else {
        wei=weishu_shibie(minimal);
    }
    for (int i=0;i<hang;i++){
        for (int j=0;j<lie;j++){
            if (arr[i][j]>=0){
                printf(" ");
            }
            printf("%d ",arr[i][j]);
            for (int x=0;x<(wei-weishu_shibie(arr[i][j]));x++){
                printf(" ");
            }
        }
        printf("\n");
    }
}

void jvzhen_get (int shuchu,int hang,int lie,int arr[hang][lie]){
    for (int i=0;i<hang;i++){
        for (int j=0;j<lie;j++){
            int num=0;
            scanf("%d",&num);
            arr[i][j]=num;
        }
        printf("\n");
    }
    if (shuchu==1){
        jvzhen_print_improved(hang,lie,arr);
    }
}

void jvzhen_get_confirm(int hang,int lie,int arr[hang][lie]){
    int check=0;
    printf("是否修改 ");
    scanf("%d",&check);
    while (check==1){
        int i=0;
        int j=0;
        printf("输入行位置 ");
        scanf("%d",&i);
        printf("输入列位置 ");
        scanf("%d",&j);
        if (i>hang||j>lie||i<1||j<1){
            printf("错误！\n");
            continue;
        }
        int num=0;
        printf("输入数字 ");
        scanf("%d",&num);
        arr[i-1][j-1]=num;
        jvzhen_print_improved(hang,lie,arr);
        printf("是否继续修改 ");
        scanf("%d",&check);
    }
}

void jvzhen_chen_changshu(int hang,int lie,int arr[hang][lie],int const_in,int ab/*0 or 1*/,int limit/*0&&hanglimits*/){
    if (ab==0){
        for (int i=limit-1;i<hang&&(limit<1||i<limit);i++){
            if (i<0){
                i=0;
            }
            for (int j=0;j<lie;j++){
                arr[i][j]=arr[i][j]*const_in;
            }
        }
    }
    else {
        for (int i=limit-1;i<hang&&(limit<1||i<limit);i++){
            for (int j=0;j<lie;j++){
                arr[i][j]=arr[i][j]/const_in;
            }
        }
    }
}

void jvzhen_hang_huajian(int hang,int weizhi,int lie,int arr[hang][lie]){
    int a=gongyinshu_muti_maxism(hang,lie,weizhi,arr);
    jvzhen_chen_changshu(hang,lie,arr,a,1,weizhi);
}

void jvzhen_hang_jiaohuan(int hang,int lie,int arr[hang][lie],int weizhi_1,int weizhi_2){
    int a;
    for (int i=0;i<lie;i++){
        a=arr[weizhi_1-1][i];
        arr[weizhi_1-1][i]=arr[weizhi_2-1][i];
        arr[weizhi_2-1][i]=a;
    }
}

void jvzhen_huajian (int hang,int lie,int arr[hang][lie]){
    int place=0;
    for (int lie_i=0;lie_i<lie;lie_i++){
        int lie_i_flag=0;
        for (int hang_check=0;hang_check<hang;hang_check++){
            if (arr[hang_check][lie_i]!=0){
                lie_i_flag=hang_check;
                if (lie_i_flag>=place){
                    break;
                }
            }
        }
        if (lie_i_flag>=place){
            place++;
            jvzhen_hang_jiaohuan(hang,lie,arr,place,lie_i_flag+1);
        }
        else {
            continue;
        }
        for (int i=0;i<hang;i++){
            if (i==place-1||arr[i][lie_i]==0){
                continue;
            }
            jvzhen_hang_huajian(hang,place,lie,arr);
            int a=arr[place-1][lie_i];
            int b=arr[i][lie_i];
            jvzhen_chen_changshu(hang,lie,arr,a,0,i+1);
            jvzhen_chen_changshu(hang,lie,arr,b,0,place);
            for (int j=lie_i;j<lie;j++){
                arr[i][j]=arr[i][j]-arr[place-1][j];
            }
            jvzhen_hang_huajian(hang,i+1,lie,arr);
        }
        jvzhen_hang_huajian(hang,place,lie,arr);
    }
    for (int i=0;i<hang;i++){
        for (int j=0;j<lie;j++){
            if (arr[i][j]!=0){
                if (arr[i][j]<0){
                    jvzhen_chen_changshu(hang,lie,arr,-1,0,i+1);
                }
                break;
            }
        }
    }
}

void packed_up_jvzhen_solve (int hang,int lie,int arr[hang][lie]){
    jvzhen_get(1,hang,lie,arr);
    jvzhen_get_confirm(hang,lie,arr);
    jvzhen_huajian(hang,lie,arr);
    jvzhen_print_improved(hang,lie,arr);
}

void humanuse_packed_up_jvzhen_solve (){
    int i=0;
    int j=0;
    printf("输入行数 ");
    scanf("%d",&i);
    printf("输入列数 ");
    scanf("%d",&j);
    const int hang=i;
    const int lie=j;
    int arr[hang][lie];
    packed_up_jvzhen_solve (hang,lie,arr);
}

int main (){
    humanuse_packed_up_jvzhen_solve();
    int c=0;
    printf("输入数字结束程序");
    scanf("%d",&c);
    return 0;
}
