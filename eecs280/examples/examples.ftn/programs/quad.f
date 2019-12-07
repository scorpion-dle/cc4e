*
* Program quad - calculate the quadratic formula roots
*
* Written by - C. Severance 12Mar92
*
      REAL A,B,C,DET,ROOT1,ROOT2
*
      PRINT *,'Enter A,B,C -'
      READ *,A,B,C
*
      DET = SQRT( B*B - 4 * A * C )
      ROOT1 = ( -1.0*B + DET ) /  ( 2 * A )
      ROOT2 = ( -1.0*B - DET ) /  ( 2 * A )
*
      PRINT *,'ROOT1 = ',ROOT1
      PRINT *,'ROOT2 = ',ROOT2
*
      END
