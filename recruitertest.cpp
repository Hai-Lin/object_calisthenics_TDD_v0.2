#include <gtest/gtest.h>
#include "Recruiter.h"

TEST(EmptyTest, emptytest) {

}

TEST(RecruiterCanPostJob, postJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = recruiter->postJob();
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, seejobs) {
	Recruiter* recruiter = new Recruiter();
	Job* job = recruiter->postJob();
	JobCollection* jobCollection = recruiter->getAllJobs();
	delete recruiter;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
