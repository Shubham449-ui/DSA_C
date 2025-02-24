class Solution{

    public int leftLeavesSum(Node root) 
    { 
        Queue<Node>q = new LinkedList<>();
        q.offer(root);
        int sum = 0;
        while(!q.isEmpty())
        {
            int l =q.size();
            for(int i=0;i<l;i++)
            {
                Node value = q.poll();
                
                if(value.left!=null)
                {
                    if(value.left.left == null && value.left.right==null)
                    {
                        sum = sum + value.left.data;
                    }
                    q.offer(value.left);
                }
                if(value.right!=null)
                {
                    q.offer(value.right);
                }
            }
        }
        
        return sum;
        
    } 

}
