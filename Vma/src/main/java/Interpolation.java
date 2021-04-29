import java.util.Locale;

public class Interpolation {
    private final double length = 4;
    public double h = length;

    public double fx(double x) {
        return Math.abs(5*Math.cos(3*x)+3);// Math.abs(5*Math.cos(3*x)+3)
    }

    public String writeFx(double[][] inter, double[] x) {//вывод многочлена Ньютона
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = inter.length - 1; i > 0; i--) {
            stringBuilder.append(String.format(Locale.US, "%.10f", inter[i][0]));
            for (int j = 0; j < i; j++) {
                if (x[j] == 0) {
                    stringBuilder.append('x');
                    continue;
                }
                stringBuilder.append("(x");
                if (x[j] > 0.) {
                    stringBuilder.append("-").append(String.format(Locale.US, "%.3f", x[j])).append(")");
                } else {
                    stringBuilder.append("+" + String.format(Locale.US, "%.3f", Math.abs(x[j]))).append(")");
                }

            }
            if (inter[i - 1][0] > .0) {
                stringBuilder.append("+");
            }
        }
        stringBuilder.append(String.format(Locale.US, "%.10f", inter[0][0]));
        return stringBuilder.toString();
    }
}
