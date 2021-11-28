#pragma once
#include<bits/stdc++.h>
#include"MinHeap.h"
#include"UnionFind.h"
#include"Weighted-graph-SparseGraph.h"
using namespace std;
template<typename Graph, typename Weight>
class Kruskal
{
public:
	Kruskal(Graph& graph)
	{
		MinHeap<Edge<Weight>> pq(graph.E());
		for (int i = 0; i < graph.V(); i++)
		{
			typename Graph::adjIterator adj(graph, i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
			{
				if (e->v() < e->w())
					pq.insert(*e);
			}
		}
		UnionFind uf(graph.V());
		while (mst.size() < graph.V() - 1 && !pq.isEmpty())
		{
			Edge<Weight> e = pq.extractMin();
			if (uf.isConnected(e.v(), e.w()))
			{
				continue;
			}
			mst.push_back(e);
			uf.unionElements(e.v(), e.w());
		}
		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++)
		{
			mstWeight += mst[i].wt();
		}
	}
	vector<Edge<Weight>> mstEdges()
	{
		return mst;
	}
	Weight result()
	{
		return mstWeight;
	}
private:
	vector<Edge<Weight>> mst;
	Weight mstWeight;
};