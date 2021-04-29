import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static String print(int n) {// Многочлен Ньютона
        Interpolation fx = new Interpolation();
        double[][] values = new double[n + 1][];
        fx.h /= n;
        double[] startValue = new double[n + 1];
        for (int i = 0; i < n + 1; i++) {
            startValue[i] = -2 + i * fx.h;
        }
        values[0] = new double[n + 1];
        for (int i = 0; i < n + 1; i++) {//расчет значений узлов
            values[0][i] = fx.fx(startValue[i]);
        }
        for (int i = 1; i < n + 1; i++) {// расчет таблицы
            double[] temp = new double[n + 1 - i];
            for (int j = 0; j < n + 1 - i; j++) {
                temp[j] = (values[i - 1][j + 1] - values[i - 1][j]) / (i * fx.h);
            }
            values[i] = temp;
        }
        return fx.writeFx(values, startValue);
    }

    public static void main(String[] args) throws IOException {
        FileWriter fileWriter = new FileWriter(new File("output.txt"));
        FileWriter fileWriter2 = new FileWriter(new File("output2.txt"));
        fileWriter.write(print(5));
        fileWriter.write("\n\n\n\n");
        fileWriter.write(print(10));
        fileWriter.write("\n\n\n\n");
        fileWriter.write(print(15));
        fileWriter.write("\n\n\n\n");
        fileWriter.write(print(20));
        fileWriter.write("\n\n\n\n");
        Cheb cheb1=new Cheb(-2,2,5);
        Cheb cheb2=new Cheb(-2,2,10);
        Cheb cheb3=new Cheb(-2,2,15);
        Cheb cheb4=new Cheb(-2,2,20);
        fileWriter2.write(cheb1.toString()+"\n\n\n\n");
        fileWriter2.write(cheb2.toString()+"\n\n\n\n");
        fileWriter2.write(cheb3.toString()+"\n\n\n\n");
        fileWriter2.write(cheb4.toString()+"\n\n\n\n");

        fileWriter.close();
        fileWriter2.close();
    }

}
