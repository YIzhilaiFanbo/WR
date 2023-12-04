import java.io.*;

public class SkipWhitespaceOutputStream extends FilterOutputStream {
    public SkipWhitespaceOutputStream(OutputStream out) {
        super(out);
    }

    @Override
    public void write(int b) throws IOException {
        // 过滤掉空格字符
        if (b != ' ') {
            super.write(b);
        }
    }
}
