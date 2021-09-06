'''
Machine learning algorithm takes audio FFT output
copied from Serial Monitor, pasted into CSV file,
then used to create ML model in a header file.
'''



import numpy as np
from glob import glob
from os.path import basename
from micromlgen import port
from sklearn.ensemble import RandomForestClassifier


def load_features(folder):
    dataset = None
    classmap = {}
    for class_idx, filename in enumerate(glob('%s/*.csv' % folder)):
        class_name = basename(filename)[:-4]
        classmap[class_idx] = class_name
        samples = np.loadtxt(filename, dtype=float, delimiter=',')
        labels = np.ones((len(samples), 1)) * class_idx
        samples = np.hstack((samples, labels))
        dataset = samples if dataset is None else np.vstack((dataset, samples))

    return dataset, classmap


def get_classifier(features):
    X, y = features[:, :-1], features[:, -1]

    return RandomForestClassifier(20, max_depth=10).fit(X, y)


if __name__ == '__main__':
    # Modify folder to the actual location of your csv files
    features, classmap = load_features('/your/csv/directory')
    classifier = get_classifier(features)
    c_code = port(classifier, classmap=classmap)
    print(c_code)
