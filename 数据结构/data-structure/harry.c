int main(int argc, char const *argv[])
{
    // 读入图 邻接矩阵
    MGraph G = BuildGraph();
    
    // 分析图
    FindAnimal();

    return 0;
}

void FindAnimal(MGraph Graph)
{
    WeightType D[MaxVertExNum][MaxVertexNum], MaxDist, MinDist;
    Vertex Animal, i;

    Floyd(Graph, D);

    MinDist = INFINITY;
    for (i = 0; i < Graph->Nv; i++)
    {
        MaxDist = FindMaxDist(D, i, Graph->Nv);
        if (MaxDist == INFINITY) {
            printf("0\n");
        }

        // 找到最长据里更小的动物
        if (MinDist > MaxDist) {
            // 更新据里 记录编号
            MinDist = MaxDist;
            Animal = i + 1;
        }
    }
    
}

// MGraph 定义
// CreateGraph InsertEdge
// BuildGraph

// Floyd 算法
// FindMaxDis(i) -> FindMin
// FindAnimal