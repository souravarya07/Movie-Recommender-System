# Movie-Recommender-System

# INTRODUCTION 

1: A recommender system or a recommendation system, is a subclass of information filtering system that seeks to predict the “rating” or “preference”, a user would give  to an item. They are primarily used in commercial applications. \
2: Recommender systems are utilized in a variety of areas and are most commonly recognized as playlist generators for video and music services like Netflix, Youtube and Spotify, product recommenders for services such as Amazon, or content recommender for social media platforms as Facebook and Twitter.  These systems can operate using a single input, like music, or multiple inputs within and across platforms like news, books, and search queries. \
3: There are also popular recommender systems for specific topics like restaurants and online dating. 

# APPROACH USED

We used Content Based approach, our recommendation system will recommend other movies which are going to use are similar to the selected movie. \
f(movie) -> movie \
Advantages: \
The model doesn’t need any data about other users, since the recommendations are specific to this user. This makes it easier to scale to a large number of users. \
The model can capture the specific interests of a user, and can recommend niche items that very few other users are interested in. 

# SIMILARITY MEASURES
Cosine similarity is a metric used to determine how similar the documents are irrespective of the size.\
Mathematically, it measures the cosine of the angle between two vectors projected in a multi-dimensional space.  In the context of recommendation system, the two vectors are the arrays containing the word counts of two documents. \
The Cosine similarity is advantageous because even if the two similar documents are far apart by the Euclidean distance because of the size, they could still have a smaller angle between them. \
“Smaller the angle, higher the similarity”. 



