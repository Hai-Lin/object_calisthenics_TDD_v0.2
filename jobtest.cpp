#include "jobtest.h"

TEST(EmptyTest, emptytest) {

}

TEST(TwoTypeOfJob, needResumeOrNot) {
	Job* atsJob = createATSJob();
	Job* JReqJob = createJReqJob();
	EXPECT_FALSE(atsJob->isThisJobNeedResume());
	EXPECT_TRUE(JReqJob->isThisJobNeedResume());
}

