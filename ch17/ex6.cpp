#include "std_lib_facilities.h"

/*
 * COMMENT:
 * On my machine, an int is 4 bytes (32-bits, or a word)
 * 1 MB (megabyte) is equal to 2^20 (1,048,576 bytes)
 * So, to allocate 4MB per iteration using the int type
 * you get: (2^20*4) / 4.
 *
 * This is interesting. I run Linux (Kubuntu 22.04 - kernel version: 6.5.0-17-generic (64-bits)).
 * The kernel eventually killed the process that was the executable running the program. After viewing
 * /var/log/syslog, this is the line I came across:
 *
 * > Feb 8 14:34:42 <hostname here> kernel: [66762.360611] Out of memory: Killed process 38119 (a.out)
 *   total-vm:5109470324kB, anon-rss:19957120kB, file-rss:384kB, shmem-rss:0kB, UID:1000 pgtables:9999004kB oom_score_adj:0
 *
 * Total virtual memory: 5109470324kB ≈ 4TB
 * anon-rss: 19957120kB (Anonymous (unmapped) memory resident set size in kilobytes. stack and heap)
 * file-rss: 384kB (File-backed memory resident set size in kilobytes)
 *
 * But I did manage to get the total before the process being killed: 4989379 MB
 *
 */

int main()
{
    try {
       
        int cnt{};
        while(true) {
			int *pi = new (nothrow) int[1048576]; // allocates 4MB (megabyte) in bytes per iteration.
            if(pi == nullptr) break;
            cnt += 4;
            cout << cnt << " MB allocated.\n";
		}

        // cout << "Total MB allocated:\t" << cnt << '\n';

        return 0;
    }
    catch(exception  &e) {
        cout << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
