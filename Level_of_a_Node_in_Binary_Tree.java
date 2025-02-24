class Solution
{
    /* Returns level of given data value */
    int getLevel(Node node, int data)  
    { 
        Queue<Node>q = new LinkedList<>();
        q.offer(node);
        int ans = 0;
        int height = 1;
        int flag = 1;
        while(!q.isEmpty())
        {
            int l = q.size();
            for(int i=0;i<l;i++)
            {
                Node value = q.poll();
                if(value.data == data)
                {
                    flag = 0;
                    ans = height;
                }
                if(value.left!=null)
                {
                    q.offer(value.left);
                }
                if(value.right!=null)
                {
                    q.offer(value.right);
                }
            }
            if(flag == 0)
            {
                break;
            }
            height++;
            
        }
        return ans;
    } 

}
