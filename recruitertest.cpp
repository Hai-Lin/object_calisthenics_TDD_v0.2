#include <gtest/gtest.h>
#include "Recruiter.h"

TEST(EmptyTest, emptytest) {

}

TEST(RecruiterCanPostJob, postJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = new Job();
	recruiter->postJob(job);
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, seejobs) {
	Recruiter* recruiter = new Recruiter();
	Job* job = new Job();
	recruiter->postJob(job);
	JobCollection* jobCollection = recruiter->getAllJobs();
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, postOneJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = new Job();
	recruiter->postJob(job);
	JobCollection* jobCollection = recruiter->getAllJobs();
	EXPECT_EQ(jobCollection->atIndex(0), job);
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job1 = new Job();
	Job* job2 = new Job();
	Job* job3 = new Job();
	recruiter->postJob(job1);
	recruiter->postJob(job2);
	recruiter->postJob(job3);
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
