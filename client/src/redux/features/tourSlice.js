import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import * as api from "../api";

export const createTour = createAsyncThunk(
    "tour/createTour",
    async ({ updatedTourData, navigate, toast }, { rejectWithValue }) => {

        try {
            const response = await api.createTour(updatedTourData);
            toast.success("Tour Created Successfully");
            navigate("/");
            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
);

export const getTours = createAsyncThunk(
    "tour/getTours",

    //we need to provide _ when passing no parameters 
    async (_, { rejectWithValue }) => {

        try {
            const response = await api.getTours();

            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)

export const getTour = createAsyncThunk(
    "tour/getTour",

    //we need to provide _ when passing no parameters 
    async (id, { rejectWithValue }) => {
        console.log("id is  in slice", id);

        try {
            const response = await api.getTour(id);

            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)






const tourSlice = createSlice({
    name: "tour",
    initialState: {
        tour: {},
        tours: [],
        //the tours only of a particular user 
        userTours: [],

        error: "",
        loading: false
    },

    extraReducers: {
        [createTour.pending]: (state, action) => {
            state.loading = true;
        },
        [createTour.fulfilled]: (state, action) => {
            state.loading = false;
            state.tours = [action.payload];


        },
        [createTour.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload;
        },


        [getTours.pending]: (state, action) => {
            state.loading = true;
        },
        [getTours.fulfilled]: (state, action) => {
            state.loading = false;
            state.tours = action.payload;


        },
        [getTours.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },
        [getTour.pending]: (state, action) => {
            state.loading = true;
        },
        [getTour.fulfilled]: (state, action) => {
            state.loading = false;
            state.tour = action.payload;


        },
        [getTour.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },



    }
});



export default tourSlice.reducer;