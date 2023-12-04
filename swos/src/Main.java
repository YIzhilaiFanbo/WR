import java.io.*;
public class Main {
    public static void main(String[] args) {
        try {
            // 从控制台读取输入字符串
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("请输入字符串：");
            String input = reader.readLine();

            // 创建自定义的输出流对象
            ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
            SkipWhitespaceOutputStream skipWhitespaceOutputStream = new SkipWhitespaceOutputStream(byteArrayOutputStream);

            // 写入过滤后的字符串
            skipWhitespaceOutputStream.write(input.getBytes());

            // 将过滤后的内容输出到控制台
            System.out.println("过滤后的字符串：");
            System.out.println(byteArrayOutputStream.toString());

            // 关闭流
            skipWhitespaceOutputStream.close();
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}