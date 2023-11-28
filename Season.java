import java.util.Scanner;

public class Season {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入月份（1-12）：");
        int month = scanner.nextInt();

        String season;
        switch (month) {
            case 3:
            case 4:
            case 5:
                season = "春季";
                break;
            case 6:
            case 7:
            case 8:
                season = "夏季";
                break;
            case 9:
            case 10:
            case 11:
                season = "秋季";
                break;
            case 12:
            case 1:
            case 2:
                season = "冬季";
                break;
            default:
                season = "输入无效，请输入1-12之间的数字";
        }

        System.out.println("该月份所属季节是：" + season);

        scanner.close(); // 关闭Scanner对象
    }
}
