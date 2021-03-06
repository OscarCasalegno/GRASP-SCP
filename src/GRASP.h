/*
 * GRASP.h
 *
 * Author: 			Victor Reyes
 * University:  	Pontificia Universidad Catolica de Valparaiso, Valparaiso, Chile
 * Created		:	August 1th 2018
 * Last Update:   	August 6th 2018
 */

#ifndef SRC_GRASP_H_
#define SRC_GRASP_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <SCP.h>
#include <rowCovering.h>
#include <Solution.h>


using namespace std;

class GRASP{
public:
	GRASP(const SCP problem, Solution solution, double MAX_TIME);


	const SCP problem;
	double MAX_TIME;
	double start_time;
	double t_lastsol;
	Solution solution;

	vector<double> weights;

	double best_solution;
	double best_time;

	void search();
	bool repairing(Solution empty_solution, Solution& solution,vector <int> rep_columns);
	void construction(bool repairing,Solution &solution);
	void penalty(Solution& solution);
	void report();
	void update_best_sol(Solution solution);
	pair<vector<int>,vector<int>> divide_list(vector<int> input_list);
	void init_lists(vector <vector <int> > & rep_lists, int nb_lists, Solution aux_solution);
	void copy_solution(Solution old_sol,Solution& new_sol);
	void penalty(Solution old_solution, Solution new_solution);
	void init_weights();
};


#endif /* SRC_GRASP_H_ */
