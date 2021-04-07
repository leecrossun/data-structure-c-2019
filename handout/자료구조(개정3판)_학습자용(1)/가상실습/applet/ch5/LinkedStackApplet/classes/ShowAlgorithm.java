
import java.awt.*;
import java.io.*;
import java.net.URL;

class ShowAlgorithm extends Panel
{

    ShowAlgorithm(URL aurl[])
    {
        url = aurl;
        tcan = new TextCanvas();
          font = new Font("Serif", Font.ITALIC, 16);
                 tcan.setFont(font);
        setData(0);
        setLayout(new BorderLayout());
        vert = new Scrollbar(1, 0, 100, 0, 1000);
        horz = new Scrollbar(0, 0, 100, 0, 200);
        add("Center", tcan);
        add("East", vert);
        add("South", horz);
    }

    String[] getFile(int i)
    {
        int j = 0;
        try
        {
            aIS = url[i].openStream();
            bIS = url[i].openStream();
        }
        catch(IOException ioexception) { }
        tmpDIS = new DataInputStream(aIS);
        tmp2DIS = new DataInputStream(bIS);
        try
        {
            while(tmpDIS.readLine() != null)
                j++;
        }
        catch(Exception exception)
        {
            System.out.println("파일에서 라인을 읽을 수 없습니다.!");
        }
        data = new String[j];
        j = 0;
        try
        {
            while((data[j] = tmp2DIS.readLine()) != null)
                j++;
        }
        catch(Exception exception1) { }
        return data;
    }

    void focus(int i)
    {
        tcan.showT(i);
    }

    void setData(int i)
    {
        tcan.setData(getFile(i));
    }

    public boolean handleEvent(Event event)
    {
        if(event.target instanceof Scrollbar)
        {
            tcan.transxy(horz.getValue(), vert.getValue());
            return true;
        } else
        {
            return super.handleEvent(event);
        }
    }

    private TextCanvas tcan;
    private Scrollbar vert;
    private Scrollbar horz;
    private InputStream aIS;
    private InputStream bIS;
    private DataInputStream tmpDIS;
    private DataInputStream tmp2DIS;
    private URL url[];
    private String data[];
    Font font;
}
