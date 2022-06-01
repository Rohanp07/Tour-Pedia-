import mongoose from 'mongoose';

const TourSchema = new mongoose.Schema({
    title: String,
    description: String,
    name: String,
    creator: String,
    tags: [String],
    imageFile: String,
    createdAt: {
        type: Date,
        default: new Date()
    },
    likeCount: {
        type: Number,
        default: 0

    }


});

const TourModel = mongoose.model('Tour', TourSchema);
export default TourModel;