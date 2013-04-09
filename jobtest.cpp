#include "jobtest.h"

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
