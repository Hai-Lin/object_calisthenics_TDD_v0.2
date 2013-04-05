#include"utility.h"

class Job {

};

class JobCollection {
	private:
		vector<Job*> jobs;
	public:
		void addJobToCollection(Job* );
};
