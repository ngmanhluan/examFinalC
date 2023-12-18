#include <stdio.h>
#include <string.h>

struct student{
    char MSSV[100];
    int Year;
    float midtermScore;
    float finalScore;
    float averageScore;
    int ranking;
};
typedef struct student Student;

void Nhap(Student st[], int n){
    for(int i = 0; i < n; i++){
        fflush(stdin);
        printf("Nhap ma so sinh vien [%d]: ", i+1);
        gets(st[i].MSSV);
        fflush(stdin);
        printf("Nam sinh: ");
        scanf("%d", &st[i].Year);
        printf("Diem thi giua ky: ");
        scanf("%f", &st[i].midtermScore);
        printf("Diem thi cuoi ky: ");
        scanf("%f", &st[i].finalScore);
    }
}

void checkYear(Student st[], int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(st[i].Year >= 1999){
            dem += 1;
        }
    }
    printf("So Luong sinh vien co nam sinh 1999 tro ve sau: %d\n", dem);
}

void DiemTB(Student st[], int n){
    for(int i = 0; i < n; i++){
        st[i].averageScore = 0.3 * st[i].midtermScore + 0.7 * st[i].finalScore;
    }
}

void ranking(Student st[], int n){
    int sl = 0;
    int sl2 = 0;
    for(int i = 0; i < n; i++){
        if(st[i].averageScore <= 4){
            printf("Sinh Vien [%d] Xep Loai D\n", i+1);
            sl += 1;
        }
        else if(st[i].averageScore > 4 && st[i].averageScore <= 6){
            printf("Sinh Vien [%d] Xep Loai C\n", i+1);
        }
        else if(st[i].averageScore > 6 && st[i].averageScore <= 8){
            printf("Sinh Vien [%d] Xep Loai B\n", i+1);
        }
        else if(st[i].averageScore > 8){
            printf("Sinh Vien [%d] Xep Loai A\n", i+1);
            sl2 += 1;
        }
    }
    printf("---------------------------------------\n");
    printf("So Luong sinh vien loai D la: %d\n", sl);
    printf("So Luong sinh vien loai A la: %d\n", sl2);
    printf("---------------------------------------\n");
}

void SoLuong(Student st[], int n){
    int sl = 0;
    for(int i = 0; i < n; i++){
        if(st[i].averageScore >= 4 && st[i].averageScore <= 8){
            sl += 1;
        }
    }
    printf("So luong sinh vien co diem TB tu 4 den 8 la: %d\n", sl);
}
int main(){
    int n;
    Student st[100];
    printf("Vui long nhap so luong sinh vien: ");
    scanf("%d", &n);
    Nhap(st, n);
    checkYear(st, n);
    DiemTB(st, n);
    ranking(st, n);
    SoLuong(st, n);
    
    return 0;
}
