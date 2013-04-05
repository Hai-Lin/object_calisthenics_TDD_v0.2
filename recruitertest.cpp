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

TEST(RecruiterCanSeeAListOfJobTheyPost, postOneJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = recruiter->postJob();
	JobCollection* jobCollection = recruiter->getAllJobs();
	EXPECT_EQ(jobCollection->atIndex(0), job);
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job1 = recruiter->postJob();
	Job* job2 = recruiter->postJob();
	Job* job3 = recruiter->postJob();
	JobCollection* jobCollection = recruiter->getAllJobs();
	EXPECT_EQ(jobCollection->atIndex(0), job1);
	EXPECT_EQ(jobCollection->atIndex(1), job2);
	EXPECT_EQ(jobCollection->atIndex(2), job3);
	delete recruiter;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
