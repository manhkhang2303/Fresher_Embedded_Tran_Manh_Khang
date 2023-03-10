#include <stdio.h>
#include <stdint.h>

void readNumber(int num);

int main(int argc, char const *argv[]) {
    int n;
    do{
      printf("Enter the number: ");
      scanf("%d", &n);   
    } while (n <= 0 || n > 9999999);
    readNumber(n);
    return 0;
}

void readNumber(int num) {
    int count;
    for (int i = num; i != 0; i /= 10)
    {
        count++;
    }

    if(count == 7) {
        switch (num / 1000000)
        {
        case 1:
            printf("Mot trieu ");
            break;
        case 2:
            printf("Hai trieu ");
            break;
        case 3:
            printf("Ba trieu ");
            break;
        case 4:
            printf("Bon trieu ");
            break;
        case 5:
            printf("Nam trieu ");
            break;
        case 6:
            printf("Sau trieu ");
            break;
        case 7:
            printf("Bay trieu ");
            break;
        case 8:
            printf("Tam trieu ");
            break;
        case 9:
            printf("Chin trieu ");
            break;    
        }
        num = num % 1000000;
        count--;
        if(num - (num % 100000) * 100000 == 0) {
            printf(" ");
        }
}
    if(count == 6) {
        switch (num / 100000)
        {
        case 0:
            printf("Khong tram ");
            break;
        case 1:
            printf("Mot tram ");
            break;
        case 2:
            printf("Hai tram ");
            break;
        case 3:
            printf("Ba tram ");
            break;
        case 4:
            printf("Bon tram ");
            break;
        case 5:
            printf("Nam tram ");
            break;
        case 6:
            printf("Sau tram ");
            break;
        case 7:
            printf("Bay tram ");
            break;
        case 8:
            printf("Tam tram ");
            break;
        case 9:
            printf("Chin tram ");
            break;
        }
        num = num % 100000;
        count--;
        if(num - (num % 10000) * 10000 == 0) {
            printf("nghin ");
        }
    }
    if(count == 5) {
        switch (num / 10000)
        {
        case 1:
            printf("Muoi ");
            break;
        case 2:
            printf("Hai muoi ");
            break;
        case 3:
            printf("Ba muoi ");
            break;
        case 4:
            printf("Bon muoi ");
            break;
        case 5:
            printf("Nam muoi ");
            break;
        case 6:
            printf("Sau muoi ");
            break;
        case 7:
            printf("Bay muoi ");
            break;
        case 8:
            printf("Tam muoi ");
            break;
        case 9:
            printf("Chin muoi ");
            break;
        default:
            printf("linh ");
            break;
        }
        num = num % 10000;
        count--;
        if(num - (num % 1000) * 1000 == 0) {
            printf("nghin ");
        }
    }
    if(count == 4) {
        switch (num / 1000)
        {
        case 1:
            printf("Mot nghin ");
            break;
        case 2:
            printf("Hai nghin ");
            break;
        case 3:
            printf("Ba nghin ");
            break;
        case 4:
            printf("Bon nghin ");
            break;
        case 5:
            printf("Nam nghin ");
            break;
        case 6:
            printf("Sau nghin ");
            break;
        case 7:
            printf("Bay nghin ");
            break;
        case 8:
            printf("Tam nghin ");
            break;
        case 9:
            printf("Chin nghin ");
            break;
        }
        num = num % 1000;
        count--;
        if(num - (num % 100) * 100 == 0) {
            printf(" ");
        }
}
    if(count == 3) {
        switch (num / 100)
        {
        case 0:
            printf("Khong tram ");
            break;
        case 1:
            printf("Mot tram ");
            break;
        case 2:
            printf("Hai tram ");
            break;
        case 3:
            printf("Ba tram ");
            break;
        case 4:
            printf("Bon tram ");
            break;
        case 5:
            printf("Nam tram ");
            break;
        case 6:
            printf("Sau tram ");
            break;
        case 7:
            printf("Bay tram ");
            break;
        case 8:
            printf("Tam tram ");
            break;
        case 9:
            printf("Chin tram ");
            break;
        }
        num = num % 100;
        count--;
        if(num - (num % 10) * 10 == 0) {
            printf("nghin ");
        }
}
    if(count == 2) {
        switch (num / 10)
        {
        case 1:
            printf("Muoi ");
            break;
        case 2:
            printf("Hai muoi ");
            break;
        case 3:
            printf("Ba muoi ");
            break;
        case 4:
            printf("Bon muoi ");
            break;
        case 5:
            printf("Nam muoi ");
            break;
        case 6:
            printf("Sau muoi ");
            break;
        case 7:
            printf("Bay muoi ");
            break;
        case 8:
            printf("Tam muoi ");
            break;
        case 9:
            printf("Chin muoi ");
            break;
        default:
            printf("linh ");
            break;
        }
        num = num % 10;
        count--;
        if(num - (num / 10) == 0) {
            printf(" ");
        }
    }
    if(count == 1) {
        switch (num)
        {
        case 1:
            printf("Mot ");
            break;
        case 2:
            printf("Hai ");
            break;
        case 3:
            printf("Ba ");
            break;
        case 4:
            printf("Bon ");
            break;
        case 5:
            printf("Nam ");
            break;
        case 6:
            printf("Sau ");
            break;
        case 7:
            printf("Bay ");
            break;
        case 8:
            printf("Tam ");
            break;
        case 9:
            printf("Chin ");
            break;
        }
    }
}
