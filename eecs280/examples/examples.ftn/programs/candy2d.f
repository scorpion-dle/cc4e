*
* candy2d - Track the inventory of a candy machine with 4 rows and 5 columns
*
* Written by - Charles Severance 18Mar92
*
* Each line read by the program is aninventory control record.  The first
* number indicates the type of transaction - 1 Stock 2 Sell 3 List.
* The next two numbers are the row and column.  The last number is the number
* of candy bars bought or sold for type 1 or 2 records.
*
* Example input:
*
* 1 2 3 20  Stocked 20 in row 2 column 3
* 2 4 4 5  Sold 5 in row 4 column 4
* 3 0 0 0  List the contents of the machine (row,col, amount ignored)
*
* Program must check for an error in the row or column.  Program
* must also not allow product to be sold if there is none in stock.
*
      INTEGER INVEN(4,5)
      INTEGER TYPE,ROW,COL,AMOUNT
*
* Initialize the inventory
*
      DO ROW=1,4
        DO COL=1,5
          INVEN(ROW,COL) = 0
        ENDDO
      ENDDO
*
*  Begin to read records
*
10    CONTINUE
      PRINT *,'Enter inventory record -'
      READ(*,*,END=20)TYPE,ROW,COL,AMOUNT
*
* Process each transaction - 1 Stock 2 Sell 3 List.
*
      IF ( TYPE.EQ.1 ) THEN
        IF ( ROW.LT.1.OR.ROW.GT.4 ) THEN
          PRINT *,'Row ',ROW,' out of range'
          GOTO 10
        ENDIF
        IF ( COL.LT.1.OR.COL.GT.5 )THEN
          PRINT *,'Column ',COL,' out of range'
          GOTO 10
        ENDIF
        INVEN(ROW,COL) = INVEN(ROW,COL) + AMOUNT
*
      ELSE IF ( TYPE.EQ.2 ) THEN
        IF ( ROW.LT.1.OR.ROW.GT.4 ) THEN
          PRINT *,'Row ',ROW,' out of range'
          GOTO 10
        ENDIF
        IF ( COL.LT.1.OR.COL.GT.5 )THEN
          PRINT *,'Column ',COL,' out of range'
          GOTO 10
        ENDIF
        IF ( INVEN(ROW,COL) .GE. AMOUNT ) THEN
          INVEN(ROW,COL) = INVEN(ROW,COL) - AMOUNT
        ELSE
          PRINT *,'Amount in ',ROW,COL,' Not sufficient'
       ENDIF
*
      ELSE IF ( TYPE.EQ.3 ) THEN
        PRINT *
        PRINT 80
        PRINT 90
        DO ROW=1,4
          PRINT 100,ROW,(INVEN(ROW,COL),COL=1,5)
         ENDDO
        PRINT *
*
      ELSE
        PRINT *,'Invalid Transaction type ',TYPE
      ENDIF
    
      GOTO 10
*
20    CONTINUE
      PRINT *
      PRINT *,'Thank you for using the candy inventory program.'
*
* Format statements - (It doesn't matter where we put these...)
*
80    FORMAT(1X,3X,'       1    2    3    4    5')
90    FORMAT(1X,3X,'----------------------------')
100   FORMAT(1X,I3,' | ',5(2X,I3))
      END
