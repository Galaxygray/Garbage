import java.io.File;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import jxl.Sheet;
import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;

public class Excel {
    
	
    public static List<Data> getAllByExcel(String file){
        List<Data> list=new ArrayList<Data>();
        try {
            Workbook rwb = Workbook.getWorkbook(new File(file));
            Sheet rs =  rwb.getSheet(0);
            int clos=rs.getColumns();
            int rows=rs.getRows();
            List<String> name = new ArrayList<String>(),def = new ArrayList<String>(),fuc = new ArrayList<String>(),intr = new ArrayList<String>(),id = new ArrayList<String>() ;
            List<Integer> num = new ArrayList<Integer>();
            String str;
            for (int i = 1; i < rows; i++) {
                    str = rs.getCell(1, i).getContents();
                    if(str.length() > 0){
                      id.add(str);
                    }
                    str = rs.getCell(2, i).getContents();
                    if(str.length() > 0){
                    	name.add(str);
                    }
                    str = rs.getCell(3, i).getContents();
                    if(str.length() > 0){
                    	System.out.println(str);
                    	fuc.add(str);
                    }
                    str = rs.getCell(4, i).getContents();
                    if(str.length() > 0){
                    	num.add(Integer.parseInt(str));
                    }
                    str = rs.getCell(5, i).getContents();
                    if(str.length() > 0){
                    	def.add(str);
                    }
                    str = rs.getCell(6, i).getContents();
                    if(str.length() > 0){
                    	intr.add(str);
                    }
            }
          // System.out.println(name.size() + " " + def.size() + " " + intr.size() + " " + num.size() + " " + id.size());
            for(int i = 0; i < name.size(); i ++){
            	list.add(new Data(id.get(i), name.get(i), fuc.get(i), num.get(i), def.get(i), intr.get(i)));
            }
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } 
        return list;
        
    }
    
    public static void Out(List<Data> list) {
        try {
            WritableWorkbook wwb = null;
             
               // 创建可写入的Excel工作簿
               String fileName = "chip.xls";
               File file=new File(fileName);
               if (!file.exists()) {
                   file.createNewFile();
               }
               //以fileName为文件名来创建一个Workbook
               wwb = Workbook.createWorkbook(file);

               // 创建工作表
               WritableSheet ws = wwb.createSheet("Test Shee 1", 0);
               
               Label label = new Label(0, 0, "序号");
               Label labelid = new Label(1, 0, "型号");
               Label labelname = new Label(2, 0, "名称");
               Label labelfuc = new Label(3, 0, "功能");
               Label labelnum = new Label(4, 0, "管脚数");
               Label labeldef = new Label(5, 0, "管脚定义");
               Label labelintr = new Label(6, 0, "芯片介绍");
               ws.addCell(label);
               ws.addCell(labelid);
               ws.addCell(labelname);
               ws.addCell(labelfuc);
               ws.addCell(labelnum);
               ws.addCell(labeldef);
               ws.addCell(labelintr);
               for (int i = 0; i < list.size(); i++) {
            	   label = new Label(0, i + 1, String.valueOf(i + 1));
            	   labelid = new Label(1, i + 1, list.get(i).getId());
                   labelname = new Label(2, i + 1, list.get(i).getName());
                   labelfuc = new Label(3, i + 1, list.get(i).getfuc());
                   labelnum = new Label(4, i + 1, String.valueOf(list.get(i).getNum()));
                   labeldef = new Label(5, i + 1, list.get(i).getdef());
                   labelintr = new Label(6, i + 1, list.get(i).getintr());
                   ws.addCell(label);
                   ws.addCell(labelid);
                   ws.addCell(labelname);
                   ws.addCell(labelfuc);
                   ws.addCell(labelnum);
                   ws.addCell(labeldef);
                   ws.addCell(labelintr);
               }
              //写进文档
               wwb.write();
              // 关闭Excel工作簿对象
               wwb.close();
             
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } 
    }
    
    
//    public static void main(String[] args) {
//        /*List<Data> all=getAllByDb();
//        for (Data Data : all) {
//            System.out.println(Data.toString());
//        }*/
//        
//    	Out(getAllByExcel("C:\\Users\\rtyui\\Desktop\\java\\DataSeach\\src\\Test1.xls"));
//        
//    }
    
}