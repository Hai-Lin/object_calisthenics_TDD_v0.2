#include <gtest/gtest.h>
#include "Recruiter.h"
#include "Job.h"

TEST(EmptyTest, emptytest) {

}

TEST(TwoTypeOfJob, ATS) {
	Job* job = new Job(ATS);
	EXPECT_FALSE(job->isThisJobNeedResume());
}

TEST(TwoTypeOfJob, JReq) {
	Job* job = new Job(JReq);
	EXPECT_TRUE(job->isThisJobNeedResume());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
