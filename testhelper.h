#ifndef TESTHELPER
#define TESTHELPER

#include "utility.h"
#include "Resume.h"
#include "JobSeekerApplyJob.h"
#include "JobSeekerSaveJob.h"
#include "RecruiterPostJob.h"
#include "SavedJob.h"

Job* createATSJob();
Job* createJReqJob();
JobSeeker* createJobSeekerWithResume();
JobSeeker* createJobSeekerWithoutResume();
#endif
