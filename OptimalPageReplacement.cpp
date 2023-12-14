#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_FRAMES = 10;
const int MAX_REFERENCE_STRING = 20;

void display(const vector<int>& frameList) {
    for (int frame : frameList)
        cout << frame << '\t';
    cout << '\n';
}

int main() {
    vector<int> frameList(MAX_FRAMES, -1); // Initializing frames with -1
    vector<int> futureDistance(MAX_FRAMES, 0);
    vector<int> pageReference(MAX_REFERENCE_STRING);
    int totalReferences, numberOfFrames, pageFaults = 0;

    cout << "Enter the total number of references: ";
    cin >> totalReferences;

    if (totalReferences <= 0 || totalReferences > MAX_REFERENCE_STRING) {
        cerr << "Invalid total number of references. Exiting.\n";
        return 1;
    }

    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < totalReferences; ++i)
        cin >> pageReference[i];

    cout << "Enter the number of frames: ";
    cin >> numberOfFrames;

    if (numberOfFrames <= 0 || numberOfFrames > MAX_FRAMES) {
        cerr << "Invalid number of frames. Exiting.\n";
        return 1;
    }

    int pageFaultCount = numberOfFrames;
    for (int currentIndex = 0; currentIndex < totalReferences; ++currentIndex) {
        bool isPageFound = false;
        bool isFrameFound = false;

        for (int frameIndex = 0; frameIndex < numberOfFrames; ++frameIndex) {
            if (frameList[frameIndex] == pageReference[currentIndex]) {
                isPageFound = true;
                isFrameFound = true;
                break;
            }
        }

        if (!isPageFound) {
            for (int frameIndex = 0; frameIndex < numberOfFrames; ++frameIndex) {
                if (frameList[frameIndex] == -1) {
                    frameList[frameIndex] = pageReference[currentIndex];
                    isFrameFound = true;
                    break;
                }
            }
        }

        if (!isFrameFound) {
            fill(futureDistance.begin(), futureDistance.end(), 0);

            for (int frameIndex = 0; frameIndex < numberOfFrames; ++frameIndex) {
                for (int futureIndex = currentIndex + 1; futureIndex < totalReferences; ++futureIndex) {
                    if (frameList[frameIndex] == pageReference[futureIndex]) {
                        futureDistance[frameIndex] = futureIndex - currentIndex;
                        break;
                    }
                }
            }

            bool isFound = false;
            for (int frameIndex = 0; frameIndex < numberOfFrames; ++frameIndex) {
                if (futureDistance[frameIndex] == 0) {
                    int replacementIndex = frameIndex;
                    isFound = true;
                    break;
                }
            }

            if (!isFound) {
                int maxDistance = futureDistance[0];
                int replacementIndex = 0;

                for (int frameIndex = 0; frameIndex < numberOfFrames; ++frameIndex) {
                    if (maxDistance < futureDistance[frameIndex]) {
                        maxDistance = futureDistance[frameIndex];
                        replacementIndex = frameIndex;
                    }
                }
            }

            frameList[replacementIndex] = pageReference[currentIndex];
            ++pageFaults;
        }

        display(frameList);
    }

    cout << "Number of page faults: " << pageFaults << endl;
    float pageFaultRate = static_cast<float>(pageFaults) / totalReferences * 100;
    cout << "Page fault rate = " << pageFaultRate << "%" << endl;

    return 0;
}
