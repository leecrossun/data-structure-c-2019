// Decompiled by Jad v1.5.7d. Copyright 2000 Pavel Kouznetsov.
// Jad home page: http://www.geocities.com/SiliconValley/Bridge/8617/jad.html
// Decompiler options: packimports(3)
// Source File Name:   TextCanvas.java

import java.awt.*;

class TextCanvas extends Canvas
{

    TextCanvas()
    {
        transx = 0;
        transy = 0;
        current = -1;
        resize(300, 400);
        //font = new Font("TimesRoman", 1, 16);
        int red = 200+50;
     int green = 200+50;
     int blue = 200;
     color = new Color(red, green, blue);
       font = new Font("Serif", 0, 16);

    }

    void transxy(int i, int j)
    {
        transx = i;
        transy = j;
        repaint();
    }

    void setData(String as[])
    {
        data = as;
        n = data.length;
        repaint();
    }

    void showT(int i)
    {
        current = i;
        repaint();
    }

    public void update(Graphics g)
    {
        paint(g);
    }

    public void paint(Graphics g)
    {
        Dimension dimension = size();
        dimension.width=1000;
        dimension.height=2000;
        if(offImage == null)
        {
            offImage = createImage(dimension.width, dimension.height);
            offG = offImage.getGraphics();
            offG.setFont(font);
        }

        offG.setColor(color);
        offG.fillRect(0, 0, dimension.width, dimension.height);
        offG.setColor(Color.black);
        g.translate(-transx, -transy);
        for(int i = 0; i < n; i++)
            if(current == i)
            {
                offG.setColor(Color.red);
                offG.fillRect(0, 20 * i + 5, size().width, 20);
                offG.setColor(Color.white);
                offG.drawString(data[i], 0, 20 * (i + 1));
            } else
            {
                offG.setColor(Color.black);
                offG.drawString(data[i], 0, 20 * (i + 1));
            }

        g.drawImage(offImage, 0, 0, this);
    }

    private int transx;
    private int transy;
    private int current;
    private int n;
    private String data[];
     Font font;
    private Image offImage;
    private Graphics offG;
    Color color;
}
