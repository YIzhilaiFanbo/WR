 import java.io.*;

    public class FileCopyTxtFiles {
        public static void main(String[] args) {
            // 指定目录
            File sourceDirectory = new File("C:/Users/a2753/Desktop/新建文件夹"); // 替换为你的源目录路径
            File destinationDirectory = new File("d:/tmp"); // 目标目录路径

            // 检查目标目录是否存在，如果不存在则创建
            if (!destinationDirectory.exists()) {
                destinationDirectory.mkdirs(); // 创建目标目录
            }

            // 查找并复制后缀名为txt的文件
            File[] txtFiles = sourceDirectory.listFiles((dir, name) -> name.toLowerCase().endsWith(".txt"));

            if (txtFiles != null) {
                for (File txtFile : txtFiles) {
                    try (Reader reader = new FileReader(txtFile);
                         Writer writer = new FileWriter(new File(destinationDirectory, txtFile.getName()))) {

                        // 逐行读取并写入到新的目标文件中
                        char[] buffer = new char[1024];
                        int charsRead;
                        while ((charsRead = reader.read(buffer)) != -1) {
                            writer.write(buffer, 0, charsRead);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                System.out.println("复制完成！");
            } else {
                System.out.println("没有找到后缀名为txt的文件！");
            }
        }
    }


