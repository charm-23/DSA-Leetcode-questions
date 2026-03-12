class Solution {
public:
    vector<int> parent, depth;

    int find(int node) {
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    bool unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB) return false;
        if (depth[rootA] < depth[rootB]) swap(rootA, rootB);
        parent[rootB] = rootA;
        if (depth[rootA] == depth[rootB]) depth[rootA]++;
        return true;
    }

    bool canAchieve(int minStrength, int n, int maxUpgrades, vector<vector<int>>& edges) {
        parent.resize(n); depth.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        int edgesUsed = 0, upgradesUsed = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], strength = edge[2], isMust = edge[3];
            if (isMust == 1) {
                if (strength < minStrength) return false;
                if (!unite(u, v)) return false;
                edgesUsed++;
            }
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], strength = edge[2], isMust = edge[3];
            if (isMust == 0 && strength >= minStrength)
                if (unite(u, v)) edgesUsed++;
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], strength = edge[2], isMust = edge[3];
            if (isMust == 0 && strength < minStrength && 2 * strength >= minStrength)
                if (unite(u, v)) { edgesUsed++; upgradesUsed++; }
        }

        return edgesUsed == n - 1 && upgradesUsed <= maxUpgrades;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> candidates;
        for (auto& edge : edges) {
            candidates.push_back(edge[2]);
            candidates.push_back(edge[2] * 2);
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        if (!canAchieve(0, n, k, edges)) return -1;

        int lo = 0, hi = (int)candidates.size() - 1, bestStability = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canAchieve(candidates[mid], n, k, edges)) {
                bestStability = candidates[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return bestStability;
    }
};