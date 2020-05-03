# Information Retrieval

This note mainly focuses on text information retrieval. It is mainly based on JHU's, [ETHzurich's](https://www.systems.ethz.ch/courses/spring2018/informationretrieval) and [Stanford's](http://web.stanford.edu/class/cs276/) information retrieval course.

## Overview

Data -> Search -> User

More detail:

-   Data: Getting documents and preprocessing documents
    -   Crawler
    -   Text preprocessing, Clustering, Information Extraction (Named Entity, Relation, Topic Models, etc.)
    -   Forward Index, Inverted Index
-   Search: Querying content (Search engine) or filtering content (Recommendation system). Not different that much.
    -   Querying: Boolean Retrieval, Vector Space Model, Probabilistic Model, Learning to Rank
    -   Filtering: Content Filtering, Collaborative Filtering, Also use Querying methods
    -   Ranking: Scoring, Link Analysis
-   User: Content presentation

## Retrieval In General

-   The way user accessing data: Push mode (Recommendation system like news feed) -> filtering content and Pull model (Search engine) -> querying content.
-   Retrieval compared to Database: Database usually holds structured data, with well-defined query semantics.
-   Know that user information need is almost always larger than the given query.
-   Search core methods: Selection (binary decision) or Ranking (Continous scoring and thresholding). If we assume the utility of a document to a user is independent of any other document and the usesr browse the results sequentially, we could rank documents in descending order of the probability that a document is relevant to the query.
-   Search results evaluation: Precision and Recall.

## General Text Preprocessing

-   Tokenization
-   Normalization: Map term variant to the same form.
-   Stemming: Extract root word.
-   Stop words: Omit common words

## Main Topics

-   [Ad Hoc Retrieval](./ad_hoc_retrieval.md)
-   [Classification and Clustering](./classification_and_clustering.md)