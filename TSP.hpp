class TSP
{
	private:
		int num_cities; // number of cities
		int ** distances; // distances matrix
	public:
		TSP(std::string); // constructor from an input file
		int get_num_cities() const;
		void print();
		int get_dist(int, int);
		// compute the distance between ci and cj
		int * Nearest_Neighbor(int *);
		// The heuristic
};
