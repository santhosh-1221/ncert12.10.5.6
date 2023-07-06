double** Mata(double v1, double v2, double v3) {
    double **vector = (double**)malloc(3 * sizeof(*vector));
    for (int i = 0; i < 3; i++) {
        vector[i] = (double*)malloc(sizeof(double));
        vector[i][0] = 0.0; // Initialize the elements to 0
    }

    vector[0][0] = v1;
    vector[1][0] = v2;
    vector[2][0] = v3;

    return vector;
}

void print(double **p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", p[i][j]);
        }
        printf("\n");
    }
}

double** Matb(double v1, double v2, double v3) {
    double **vector = (double**)malloc(3 * sizeof(*vector));
    for (int i = 0; i < 3; i++) {
        vector[i] = (double*)malloc(sizeof(double));
        vector[i][0] = 0.0; // Initialize the elements to 0
    }

    vector[0][0] = v1;
    vector[1][0] = v2;
    vector[2][0] = v3;

    return vector;
}

double **matc(double **mat1, double **mat2) {
    double **sum = (double**)malloc(3 * sizeof(*sum));
    for (int i = 0; i < 3; i++) {
        sum[i] = (double*)malloc(sizeof(double));
        sum[i][0] = mat1[i][0] + mat2[i][0];
    }

    return sum;
}

double linalg_norm(double **a, int m) {
    double norm = 0.0;

    for (int i = 0; i < m; i++) {
        norm += a[i][0] * a[i][0];
    }

    return sqrt(norm);
}

double **scalarProduct(double scalar, double **mat) {
    double **product = (double**)malloc(3 * sizeof(*product));

    for (int i = 0; i < 3; i++) {
        product[i] = (double*)malloc(sizeof(double));
        product[i][0] = mat[i][0] * scalar;
    }

    return product;
}
void save_a(double **a, int rows, int cols)
{
	FILE *fp;
	fp = fopen("a.dat", "w");
	//fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
	  //fprintf(fp, "[");
	  for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {  
	      //fprintf(fp, ", ");  
	      }
    } 
	  fprintf(fp, "\n"); 
  }
  fclose(fp);
}

void save_b(double **a, int rows, int cols)
{
	FILE *fp;
	fp = fopen("b.dat", "w");
	//fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
	  //fprintf(fp, "[");
	  for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {  
	      //fprintf(fp, ", ");  
	      }
    } 
	  fprintf(fp, "\n"); 
  }
  fclose(fp);
}

void save_vector(double **a, int rows, int cols)
{
	FILE *fp;
	fp = fopen("vector.dat", "w");
	//fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
	  //fprintf(fp, "[");
	  for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);
      if (j < cols - 1) {  
	      //fprintf(fp, ", ");  
	      }
    } 
	  fprintf(fp, "\n"); 
  }
  fclose(fp);
}
