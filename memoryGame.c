#include <stdio.h>
#include <stdlib.h>

int gameBoard[50][50], i, j, k=0, computerMemory[500];
char gameBoardCovered[50][50];

void printKolayBoard(void){
    printf("Koordinatlar  ");
    for(j=0;j<4;j++){
        printf("%d ",j+1);
    }
    printf("\n");
    for(i=0;i<4;i++){
            printf("%d\t      ", i+1);
        for(j=0;j<4;j++){
            printf("%d ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void printOrtaBoard(void){
    printf("Koordinatlar  ");
    for(j=0;j<6;j++){
        printf("%d \t",j+1);
    }
    printf("\n");
    for(i=0;i<6;i++){
            printf("%d\t      ", i+1);
        for(j=0;j<6;j++){
            if(gameBoard[i][j]<10){
                printf("%d \t", gameBoard[i][j]);
            }
            else{
                printf("%d\t", gameBoard[i][j]);
            }
        }
        printf("\n");
    }
}

void printZorBoard(void){
    printf("Koordinatlar  ");
    for(j=0;j<8;j++){
        printf("%d \t",j+1);
    }
    printf("\n");
    for(i=0;i<8;i++){
            printf("%d\t      ", i+1);
        for(j=0;j<8;j++){
            if(gameBoard[i][j]<10){
                printf("%d \t", gameBoard[i][j]);
            }
            else{
                printf("%d\t", gameBoard[i][j]);
            }
        }
        printf("\n");
    }
}

void randKolayBoard(void){
    int randomList[15];
    k=1;
    for (i=0;i<15;i+=2){
        randomList[i]=k;
        randomList[i+1]=randomList[i];
        k++;
    }
    for (i = 0; i < 16 - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (16 - i) + 1);
          int t = randomList[j];
          randomList[j] = randomList[i];
          randomList[i] = t;
        }
    k=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            gameBoard[i][j] = randomList[k];
            k++;
        }
    }
}

void randOrtaBoard(void){
    int randomList[35];
    k=1;
    for (i=0;i<35;i+=2){
        randomList[i]=k;
        randomList[i+1]=randomList[i];
        k++;
    }
    for (i = 0; i < 36 - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (36 - i) + 1);
          int t = randomList[j];
          randomList[j] = randomList[i];
          randomList[i] = t;
        }
    k=0;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            gameBoard[i][j] = randomList[k];
            k++;
        }
    }
}

void randZorBoard(void){
    int randomList[63];
    k=1;
    for (i=0;i<63;i+=2){
        randomList[i]=k;
        randomList[i+1]=randomList[i];
        k++;
    }
    for (i = 0; i < 64 - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (64 - i) + 1);
          int t = randomList[j];
          randomList[j] = randomList[i];
          randomList[i] = t;
        }
    k=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            gameBoard[i][j] = randomList[k];
            k++;
        }
    }
}

void funcKolayBoardCovered(void){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(gameBoard[i][j] != 0){
                gameBoardCovered[i][j] = '*';
            }
            else{
                gameBoardCovered[i][j] = '-';
            }
        }
    }
}

void funcOrtaBoardCovered(void){
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(gameBoard[i][j] != 0){
                gameBoardCovered[i][j] = '*';
            }
            else{
                gameBoardCovered[i][j] = '-';
            }
        }
    }
}

void funcZorBoardCovered(void){
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(gameBoard[i][j] != 0){
                gameBoardCovered[i][j] = '*';
            }
            else{
                gameBoardCovered[i][j] = '-';
            }
        }
    }
}

void printKolayBoardCovered(void){
    printf("Koordinatlar  ");
    for(j=0;j<4;j++){
        printf("%d ",j+1);
    }
    printf("\n");
    for(i=0;i<4;i++){
            printf("%d\t      ", i+1);
        for(j=0;j<4;j++){
            printf("%c ", gameBoardCovered[i][j]);
        }
        printf("\n");
    }
}

void printOrtaBoardCovered(void){
    printf("Koordinatlar  ");
    for(j=0;j<6;j++){
        printf("%d ",j+1);
    }
    printf("\n");
    for(i=0;i<6;i++){
            printf("%d\t      ", i+1);
        for(j=0;j<6;j++){
            printf("%c ", gameBoardCovered[i][j]);
        }
        printf("\n");
    }
}

void printZorBoardCovered(void){
    printf("Koordinatlar  ");
    for(j=0;j<8;j++){
        printf("%d ",j+1);
    }
    printf("\n");
    for(i=0;i<8;i++){
            printf("%d\t      ", i+1);
        for(j=0;j<8;j++){
            printf("%c ", gameBoardCovered[i][j]);
        }
        printf("\n");
    }
}

void printComputerMemory(void){
    printf("\nBilgisayar Hafizasi: ");
    for(i=0;i<6;i++){
        printf("%d ", computerMemory[i]);
    }
    printf("\n");
}

int main(){
    /*for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            gameBoard[i][j]=0;
        }
    }*/
    time_t t;
    srand((unsigned) time(&t));
    int gameMode=0, scoreUser=0, scoreComputer=0, firstGuessRow, firstGuessColumn, secondGuessRow, secondGuessColumn, computerFirstGuessRow, computerFirstGuessColumn, computerSecondGuessRow, computerSecondGuessColumn, temp=0, cond=0, isFound=0, beraberlik=0, winCond=0;

    for(i=0;i<100;i++){
        computerMemory[i]=-1;  //Hata olusmasina karsin onlem amacli
    }
    printf("Oyun zorlugu seciniz 1-->Kolay, 2-->Orta, 3-->Zor: ");
    scanf("%d", &gameMode);
    while(gameMode==1){
        randKolayBoard();
        funcKolayBoardCovered();
        printKolayBoardCovered();
        while(winCond==0 && beraberlik==0){
            printf("Oyun sirasi: Oyuncu\n");
            printf("Lutfen aralarinda bir bosluk birakicak sekilde ilk tahmininizin koordinatlarini giriniz: ");
            scanf("%d %d", &firstGuessRow, &firstGuessColumn);
            firstGuessRow--; firstGuessColumn--;
            printf("\nIlk Tahmininiz: %d", gameBoard[firstGuessRow][firstGuessColumn]);
            printf("\nLutfen aralarinda bir bosluk birakicak sekilde ikinci tahmininizin koordinatlarini giriniz: ");
            scanf("%d %d", &secondGuessRow, &secondGuessColumn);
            secondGuessRow--; secondGuessColumn--;
            printf("\nIkinci Tahmininiz: %d", gameBoard[secondGuessRow][secondGuessColumn]);
            if(gameBoard[firstGuessRow][firstGuessColumn] == gameBoard[secondGuessRow][secondGuessColumn]){
                printf("\nTahmininiz Dogru!!");
                scoreUser++;
                printf("\nOyuncu Skor: %d", scoreUser);
                gameBoard[firstGuessRow][firstGuessColumn] = 0;
                gameBoard[secondGuessRow][secondGuessColumn]= 0;
            }
            printf("\n\n");
            funcKolayBoardCovered();
            printKolayBoardCovered();
            computerMemory[0]=gameBoard[firstGuessRow][firstGuessColumn];
            computerMemory[1]=gameBoard[secondGuessRow][secondGuessColumn];
            do{
                computerFirstGuessRow = rand()%4;
                computerFirstGuessColumn = rand()%4;
            }while(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == 0);
            printf("\nBilgisayarin ilk tahmin koordinatlari: %d %d\n", computerFirstGuessRow + 1, computerFirstGuessColumn + 1);
            printf("Bilgisayarin ilk tahmini: %d\n", gameBoard[computerFirstGuessRow][computerFirstGuessColumn]);
            if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == computerMemory[0] && (computerFirstGuessRow != firstGuessRow || computerFirstGuessColumn != firstGuessColumn)){
                printf("\nBilgisayarin hafizasindaki ile eslesme saglandi...\n");
                gameBoard[computerFirstGuessRow][computerFirstGuessColumn] = 0;
                gameBoard[firstGuessRow][firstGuessColumn] = 0;
                scoreComputer++;
            }
            else if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == computerMemory[1] && (computerFirstGuessRow != secondGuessRow || computerFirstGuessColumn != secondGuessColumn)){
                printf("\nBilgisayarin hafizasindaki ile eslesme saglandi...\n");
                gameBoard[computerFirstGuessRow][computerFirstGuessColumn] = 0;
                gameBoard[secondGuessRow][secondGuessColumn] = 0;
                scoreComputer++;
            }
            else{
                do{
                    computerSecondGuessRow = rand()%4;
                    computerSecondGuessColumn = rand()%4;
                }while(computerFirstGuessRow == computerSecondGuessRow && computerFirstGuessColumn == computerSecondGuessColumn || gameBoard[computerSecondGuessRow][computerSecondGuessColumn] == 0);
                printf("\nBilgisayarin ikinci tahmin koordinatlari: %d %d", computerSecondGuessRow + 1, computerSecondGuessColumn + 1);
                printf("\nBilgisayarin ikinci tahmini: %d\n", gameBoard[computerSecondGuessRow][computerSecondGuessColumn]);
                if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == gameBoard[computerSecondGuessRow][computerSecondGuessColumn]){
                    gameBoard[computerFirstGuessRow][computerFirstGuessColumn] = 0;
                    gameBoard[computerSecondGuessRow][computerSecondGuessColumn] = 0;
                    scoreComputer++;
                }
            }
            printf("\n\n");
            funcKolayBoardCovered();
            printKolayBoardCovered();
            printf("\nOyuncu Skor: %d", scoreUser);
            printf("\nBilgisayar Skor: %d", scoreComputer);
            printf("\n\n");
            if(scoreUser == 4 && scoreComputer == 4){
                beraberlik++;
            }
            else if (scoreUser == 5 || scoreComputer == 5){
                winCond++;
            }
        }
        gameMode = -1;
    }




    while(gameMode==2){
        randOrtaBoard();
        funcOrtaBoardCovered();
        printOrtaBoard();
        while(winCond==0 && beraberlik==0){
            printf("Oyun sirasi: Oyuncu\n");
            printf("Lutfen aralarinda bir bosluk birakicak sekilde ilk tahmininizin koordinatlarini giriniz: ");
            scanf("%d %d", &firstGuessRow, &firstGuessColumn);
            firstGuessRow--; firstGuessColumn--;
            printf("\nIlk Tahmininiz: %d", gameBoard[firstGuessRow][firstGuessColumn]);
            printf("\nLutfen aralarinda bir bosluk birakicak sekilde ikinci tahmininizin koordinatlarini giriniz: ");
            scanf("%d %d", &secondGuessRow, &secondGuessColumn);
            secondGuessRow--; secondGuessColumn--;
            printf("\nIkinci Tahmininiz: %d", gameBoard[secondGuessRow][secondGuessColumn]);
            if(gameBoard[firstGuessRow][firstGuessColumn] == gameBoard[secondGuessRow][secondGuessColumn]){
                printf("\nTahmininiz Dogru!!");
                scoreUser++;
                printf("\nOyuncu Skor: %d", scoreUser);
                gameBoard[firstGuessRow][firstGuessColumn] = 0;
                gameBoard[secondGuessRow][secondGuessColumn]= 0;
                temp++;
            }
            printf("\n\n");
            funcOrtaBoardCovered();
            printOrtaBoardCovered();
            if(temp == 0){
                for(i=0;i<6;i++){
                        if(computerMemory[i] == -1){
                            temp++;
                        }
                    }
                i=0;
                while(cond == 0){
                    if(computerMemory[i] == -1){
                        computerMemory[i] = gameBoard[firstGuessRow][firstGuessColumn];
                        if(computerMemory[i+1] == -1){
                            computerMemory[i+1] = gameBoard[secondGuessRow][secondGuessColumn];
                            cond++;
                        }
                        else{
                            for(j=0;j<5;i++){
                                computerMemory[j]=computerMemory[j+1];
                            }
                            computerMemory[5] = gameBoard[secondGuessRow][secondGuessColumn];
                            cond++;
                        }
                    }
                    else if(temp == 0){
                        for(i=2;i<6;i++){
                            computerMemory[i-2] = computerMemory[i];
                        }
                        computerMemory[4] = gameBoard[firstGuessRow][firstGuessColumn];
                        computerMemory[5] = gameBoard[secondGuessRow][secondGuessColumn];
                        cond++;
                    }
                    i++;
                }
            }
            temp=0;
            cond=0;
            do{
                computerFirstGuessRow = rand()%6;
                computerFirstGuessColumn = rand()%6;
            }while(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == 0);
            printf("\nBilgisayarin ilk tahmin koordinatlari: %d %d\n", computerFirstGuessRow + 1, computerFirstGuessColumn + 1);
            printf("Bilgisayarin ilk tahmini: %d\n", gameBoard[computerFirstGuessRow][computerFirstGuessColumn]);
            for(i=0;i<6;i++){
                if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == computerMemory[i]){
                    isFound = 1;
                }
            }

            if(isFound == 1 && (computerFirstGuessRow != firstGuessRow || computerFirstGuessColumn != firstGuessColumn)){
                printf("\nBilgisayarin hafizasindaki ile eslesme saglandi...\n");

                for(i=0;i<6;i++){
                    for(k=0;k<6;k++){
                        if(gameBoard[i][k] == gameBoard[computerFirstGuessRow][computerFirstGuessColumn]){
                            gameBoard[i][k] = 0;
                        }
                    }
                }
                scoreComputer++;
                for(i=0;i<6;i++){
                    if(computerMemory[i] == gameBoard[firstGuessRow][firstGuessColumn]){
                        temp = i;
                    }
                }
                for(i=temp+1;i<6;i++){
                    computerMemory[i-1] = computerMemory[i];
                }
                computerMemory[5] = -1;
                temp = 0;
                isFound = 0;
            }

            else{
                do{
                    computerSecondGuessRow = rand()%6;
                    computerSecondGuessColumn = rand()%6;
                }while(computerFirstGuessRow == computerSecondGuessRow && computerFirstGuessColumn == computerSecondGuessColumn || gameBoard[computerSecondGuessRow][computerSecondGuessColumn] == 0);
                printf("\nBilgisayarin ikinci tahmin koordinatlari: %d %d", computerSecondGuessRow + 1, computerSecondGuessColumn + 1);
                printf("\nBilgisayarin ikinci tahmini: %d\n", gameBoard[computerSecondGuessRow][computerSecondGuessColumn]);
                if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == gameBoard[computerSecondGuessRow][computerSecondGuessColumn]){
                    gameBoard[computerFirstGuessRow][computerFirstGuessColumn] = 0;
                    gameBoard[computerSecondGuessRow][computerSecondGuessColumn] = 0;
                    scoreComputer++;
                    temp++;
                }
                if(temp == 0){
                    for(i=0;i<6;i++){
                        if(computerMemory[i] == -1){
                            temp++;
                        }
                    }
                i=0;
                while(cond == 0){
                    if(computerMemory[i] == -1){
                        computerMemory[i] = gameBoard[computerFirstGuessRow][computerFirstGuessColumn];
                        if(computerMemory[i+1] == -1){
                            computerMemory[i+1] = gameBoard[computerSecondGuessRow][computerSecondGuessColumn];
                            cond++;
                        }
                        else{
                            for(j=0;j<5;j++){
                                computerMemory[j]=computerMemory[j+1];
                            }
                            computerMemory[5] = gameBoard[computerSecondGuessRow][computerSecondGuessColumn];
                            cond++;
                        }
                    }
                    else if(temp == 0){
                        for(i=2;i<6;i++){
                            computerMemory[i-2] = computerMemory[i];
                        }
                        computerMemory[4] = gameBoard[computerFirstGuessRow][computerFirstGuessColumn];
                        computerMemory[5] = gameBoard[computerSecondGuessRow][computerSecondGuessColumn];
                        cond++;
                    }
                    i++;
                }
            }
            temp=0;
            cond=0;
            }

            printf("\n\n");

            funcOrtaBoardCovered();
            printOrtaBoardCovered();
            printf("\nOyuncu Skor: %d", scoreUser);
            printf("\nBilgisayar Skor: %d", scoreComputer);
            printf("\n\n");
            if(scoreUser == 9 && scoreComputer == 9){
                beraberlik++;
            }
            else if (scoreUser == 10 || scoreComputer == 10){
                winCond++;
            }
        }
        gameMode = -1;
    }



    while(gameMode==3){
        randZorBoard();
        funcZorBoardCovered();
        printZorBoard();
        while(winCond==0 && beraberlik==0){
            printf("Oyun sirasi: Oyuncu\n");
            printf("Lutfen aralarinda bir bosluk birakicak sekilde ilk tahmininizin koordinatlarini giriniz: ");
            scanf("%d %d", &firstGuessRow, &firstGuessColumn);
            firstGuessRow--; firstGuessColumn--;
            printf("\nIlk Tahmininiz: %d", gameBoard[firstGuessRow][firstGuessColumn]);
            printf("\nLutfen aralarinda bir bosluk birakicak sekilde ikinci tahmininizin koordinatlarini giriniz: ");
            scanf("%d %d", &secondGuessRow, &secondGuessColumn);
            secondGuessRow--; secondGuessColumn--;
            printf("\nIkinci Tahmininiz: %d", gameBoard[secondGuessRow][secondGuessColumn]);
            if(gameBoard[firstGuessRow][firstGuessColumn] == gameBoard[secondGuessRow][secondGuessColumn]){
                printf("\nTahmininiz Dogru!!");
                scoreUser++;
                printf("\nOyuncu Skor: %d", scoreUser);
                gameBoard[firstGuessRow][firstGuessColumn] = 0;
                gameBoard[secondGuessRow][secondGuessColumn]= 0;
                temp++;
            }
            printf("\n\n");

            funcZorBoardCovered();
            printZorBoardCovered();
            if(temp == 0){
                for(i=0;i<16;i++){
                        if(computerMemory[i] == -1){
                            temp++;
                        }
                    }
                i=0;
                while(cond == 0){
                    if(computerMemory[i] == -1){
                        computerMemory[i] = gameBoard[firstGuessRow][firstGuessColumn];
                        if(computerMemory[i+1] == -1){
                            computerMemory[i+1] = gameBoard[secondGuessRow][secondGuessColumn];
                            cond++;
                        }
                        else{
                            for(j=0;j<15;i++){
                                computerMemory[j]=computerMemory[j+1];
                            }
                            computerMemory[15] = gameBoard[secondGuessRow][secondGuessColumn];
                            cond++;
                        }
                    }
                    else if(temp == 0){
                        for(i=2;i<16;i++){
                            computerMemory[i-2] = computerMemory[i];
                        }
                        computerMemory[14] = gameBoard[firstGuessRow][firstGuessColumn];
                        computerMemory[15] = gameBoard[secondGuessRow][secondGuessColumn];
                        cond++;
                    }
                    i++;
                }
            }
            temp=0;
            cond=0;
            do{
                computerFirstGuessRow = rand()%8;
                computerFirstGuessColumn = rand()%8;
            }while(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == 0);
            printf("\nBilgisayarin ilk tahmin koordinatlari: %d %d\n", computerFirstGuessRow + 1, computerFirstGuessColumn + 1);
            printf("Bilgisayarin ilk tahmini: %d\n", gameBoard[computerFirstGuessRow][computerFirstGuessColumn]);
            for(i=0;i<16;i++){
                if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == computerMemory[i]){
                    isFound = 1;
                }
            }

            if(isFound == 1 && (computerFirstGuessRow != firstGuessRow || computerFirstGuessColumn != firstGuessColumn)){
                printf("\nBilgisayarin hafizasindaki ile eslesme saglandi...\n");
                for(i=0;i<8;i++){
                    for(k=0;k<8;k++){
                        if(gameBoard[i][k] == gameBoard[computerFirstGuessRow][computerFirstGuessColumn]){
                            gameBoard[i][k] = 0;
                        }
                    }
                }
                scoreComputer++;
                for(i=0;i<16;i++){
                    if(computerMemory[i] == gameBoard[firstGuessRow][firstGuessColumn]){
                        temp = i;
                    }
                }
                for(i=temp+1;i<16;i++){
                    computerMemory[i-1] = computerMemory[i];
                }
                computerMemory[15] = -1;
                temp = 0;
                isFound = 0;
            }

            else{
                do{
                    computerSecondGuessRow = rand()%8;
                    computerSecondGuessColumn = rand()%8;
                }while(computerFirstGuessRow == computerSecondGuessRow && computerFirstGuessColumn == computerSecondGuessColumn || gameBoard[computerSecondGuessRow][computerSecondGuessColumn] == 0);
                printf("\nBilgisayarin ikinci tahmin koordinatlari: %d %d", computerSecondGuessRow + 1, computerSecondGuessColumn + 1);
                printf("\nBilgisayarin ikinci tahmini: %d\n", gameBoard[computerSecondGuessRow][computerSecondGuessColumn]);
                if(gameBoard[computerFirstGuessRow][computerFirstGuessColumn] == gameBoard[computerSecondGuessRow][computerSecondGuessColumn]){
                    gameBoard[computerFirstGuessRow][computerFirstGuessColumn] = 0;
                    gameBoard[computerSecondGuessRow][computerSecondGuessColumn] = 0;
                    scoreComputer++;
                    temp++;
                }
                if(temp == 0){
                    for(i=0;i<16;i++){
                        if(computerMemory[i] == -1){
                            temp++;
                        }
                    }
                i=0;
                while(cond == 0){
                    if(computerMemory[i] == -1){
                        computerMemory[i] = gameBoard[computerFirstGuessRow][computerFirstGuessColumn];
                        if(computerMemory[i+1] == -1){
                            computerMemory[i+1] = gameBoard[computerSecondGuessRow][computerSecondGuessColumn];
                            cond++;
                        }
                        else{
                            for(j=0;j<15;j++){
                                computerMemory[j]=computerMemory[j+1];
                            }
                            computerMemory[5] = gameBoard[computerSecondGuessRow][computerSecondGuessColumn];
                            cond++;
                        }
                    }
                    else if(temp == 0){
                        for(i=2;i<16;i++){
                            computerMemory[i-2] = computerMemory[i];
                        }
                        computerMemory[4] = gameBoard[computerFirstGuessRow][computerFirstGuessColumn];
                        computerMemory[5] = gameBoard[computerSecondGuessRow][computerSecondGuessColumn];
                        cond++;
                    }
                    i++;
                }
            }
            temp=0;
            cond=0;
            }

            printf("\n\n");

            funcZorBoardCovered();
            printZorBoardCovered();
            printf("\nOyuncu Skor: %d", scoreUser);
            printf("\nBilgisayar Skor: %d", scoreComputer);
            printf("\n\n");
            if(scoreUser == 16 && scoreComputer == 16){
                beraberlik++;
            }
            else if (scoreUser == 17 || scoreComputer == 17){
                winCond++;
            }
        }
        gameMode = -1;
    }

    if(scoreUser == 5 || scoreUser == 10 || scoreUser == 17){
        printf("\nTebrikler kazandiniz!! Skorunuz: %d", scoreUser);
    }
    else if(scoreUser == 4 || scoreUser == 9 || scoreUser == 16){
        printf("\nBerabere kaldiniz... Skorunuz: %d", scoreUser);
    }
    else{
        printf("\nKaybettiniz. Skorunuz: %d", scoreUser);
    }


    return 0;
}
