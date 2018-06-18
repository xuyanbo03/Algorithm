class Solution{
public:
    bool is(string preorder){
        int positions=1;
        for(int i=0;i<preorder.size();++i){
            if(preorder[i]==','){
            	preorder[i]=' ';
			} 
        }
        istringstream out(preorder);
        string str;
        while(out>>str){
        	if(--positions<0){
        		return false;
			}
			if(str!="#"){
				positions+=2;
			}
		}
		return positions==0;
    }
}
