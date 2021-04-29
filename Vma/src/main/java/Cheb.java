import java.util.List;
import java.util.Locale;

public class Cheb {
    private double[] xValues;
    private double[][] table;
    public double countFunction(double xValue){
        return Math.abs(5*Math.cos(3*xValue)+3);//Math.pow(xValue,3)*Math.cos(3*xValue-1)
    }
    Cheb(int a,int b,int n){
        xValues=new double[ n+1];
        for (int i = 0; i <= n; i++) {
            xValues[i]= (a+b)/2 + ((b-a)/2)*Math.cos(((double) (2*i+1)/(2*n+1))*Math.PI);
        }
        table=new double[n+1][];
        table[0] = new double[n + 1];
        for (int i = 0; i < n + 1; i++) {// расчет значений узлов
            table[0][i] = countFunction(xValues[i]);
        }
        for (int i = 1; i < n + 1; i++) {// расчет таблицы
            double[] temp = new double[n + 1 - i];
            for (int j = 0; j < n + 1 - i; j++) {
                temp[j] =( table[i - 1][j + 1] - table[i - 1][j]) / (xValues[j+i]-xValues[j]);
            }
            table[i] = temp;
        }
    }

    @Override
    public String toString() {// вывод многочлена
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = table.length - 1; i > 0; i--) {
            stringBuilder.append(String.format(Locale.US, "%.10f", table[i][0]));
            for (int j = 0; j < i; j++) {
                if (xValues[j] == 0) {
                    stringBuilder.append('x');
                    continue;
                }
                stringBuilder.append("(x");
                if (xValues[j] > 0.) {
                    stringBuilder.append("-").append(String.format(Locale.US, "%.3f", xValues[j])).append(")");
                } else {
                    stringBuilder.append("+" + String.format(Locale.US, "%.3f", Math.abs(xValues[j]))).append(")");
                }

            }
            if (table[i - 1][0] > .0) {
                stringBuilder.append("+");
            }
        }
        stringBuilder.append(String.format(Locale.US, "%.10f", table[0][0]));
        return stringBuilder.toString();
    }
}
