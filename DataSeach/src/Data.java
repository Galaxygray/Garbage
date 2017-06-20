public class Data {
    private String id;
    private String name;  
    private String fuc;
    private int num;
    private String def;
    private String intr;
    
    public Data() {
    }
    public Data(String id, String name, String fuc, int num,String def, String intr) {
        this.id = id;
        this.name = name;
        this.fuc = fuc;
        this.num = num;
        this.def = def;
        this.intr = intr;
    }
    
    @Override
    public String toString() {
       return "序号: " +id + "\n" + "名称: " + getName() + "\n" + "功能: " + getfuc() + "\n" + " 管脚数: " + num + "\n" + "定义: " + getdef() + "\n" + "介绍: " + getintr() + "\n";
    }
    public String getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public String getfuc() {
        return fuc;
    }
    public String getintr() {
    	StringBuilder res = new StringBuilder();
    	for(int i = 1; (i  - 1)* 30 < intr.length(); i ++){
    		if(i * 30 >= intr.length())
    			res.append(intr.substring((i - 1) * 30) + '\n');
    		else
    			res.append(intr.substring((i - 1) * 30, i * 30) + '\n');
    	}
        return intr;
    }
    public String getdef() {
    	String[] t = def.split(" ");
    	StringBuilder res = new StringBuilder();
    	for(int i = 0; i < t.length; i ++){
    		if(t[i].length() > 0)
    		res.append(t[i] + '\n');
    	}
        return res.toString();
    }
    public int getNum() {
        return num;
    }
    
    
    
    
}