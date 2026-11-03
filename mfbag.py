def main():
  print("请输入信息\n")
  N,V=map(int,input().split())
  n = [0 for _ in range(N+1)]
  m = [0 for _ in range(N+1)]
  b = [0 for _ in range(V+1)]
  for i in range(1,N+1):
    n[i],m[i]=map(int,input().split())
    for k in range(1,N+1):
        for j in range(n[k],V+1):
            b[j]=max(b[j],b[j - n[k]]+m[k])
  print(b[V])
main()
