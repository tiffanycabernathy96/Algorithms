#pragma once
namespace AMGraph {
	struct Edge {
		int start, end, weight;
		Edge(int start, int end, int weight);
		Edge();
		bool operator==(const Edge iEdge);
	};
}